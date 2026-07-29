// Link: https://leetcode.com/problems/maximize-count-of-distinct-primes-after-split/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> seg, lazy;

    void build(int node, int l, int r, vector<int>& init) {
        if (l == r) { seg[node] = init[l]; return; }
        int m = (l + r) / 2;
        build(node*2, l, m, init);
        build(node*2+1, m+1, r, init);
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }

    void push(int node) {
        if (lazy[node] != 0) {
            for (int c : {node*2, node*2+1}) {
                seg[c] += lazy[node];
                lazy[c] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql || ql > qr) return;
        if (ql <= l && r <= qr) {
            seg[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int m = (l + r) / 2;
        update(node*2, l, m, ql, qr, val);
        update(node*2+1, m+1, r, ql, qr, val);
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }

    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        const int MAXV = 100001;
        vector<bool> isPrime(MAXV, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long long)i * i < MAXV; i++)
            if (isPrime[i])
                for (int j = i * i; j < MAXV; j += i) isPrime[j] = false;

        vector<set<int>> pos(MAXV);
        vector<int> indPrefix(n, 0), indSuffix(n, 0);

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (isPrime[v]) pos[v].insert(i);
        }
        for (int v = 0; v < MAXV; v++) {
            if (pos[v].empty()) continue;
            indPrefix[*pos[v].begin()] = 1;
            indSuffix[*pos[v].rbegin()] = 1;
        }

        // f(k) for k=0..n-1 as segment tree leaves (only k=1..n-1 meaningful, k=0 unused)
        vector<int> initF(n, 0);
        {
            vector<int> prefSum(n + 1, 0);
            for (int i = 0; i < n; i++) prefSum[i+1] = prefSum[i] + indPrefix[i];
            vector<int> sufSum(n + 1, 0); // sufSum[i] = sum indSuffix[i..n-1]
            for (int i = n - 1; i >= 0; i--) sufSum[i] = sufSum[i+1] + indSuffix[i];
            for (int k = 1; k < n; k++) initF[k] = prefSum[k] + sufSum[k];
            initF[0] = INT_MIN; // invalid split
        }

        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, initF);

        auto rangeAddPrefix = [&](int i, int delta) {
            // indicatorPrefix[i] changed by delta -> f(k) += delta for k in [i+1, n-1]
            if (i + 1 <= n - 1) update(1, 0, n - 1, i + 1, n - 1, delta);
        };
        auto rangeAddSuffix = [&](int i, int delta) {
            // indicatorSuffix[i] changed by delta -> f(k) += delta for k in [1, i]
            if (1 <= i) update(1, 0, n - 1, 1, i, delta);
        };

        vector<int> ans;
        for (auto& qr : queries) {
            int idx = qr[0], val = qr[1];
            int oldVal = nums[idx];

            if (oldVal != val) {
                if (isPrime[oldVal]) {
                    auto& s = pos[oldVal];
                    bool wasFirst = (*s.begin() == idx);
                    bool wasLast = (*s.rbegin() == idx);
                    s.erase(idx);
                    if (wasFirst) {
                        indPrefix[idx] = 0;
                        rangeAddPrefix(idx, -1);
                        if (!s.empty()) {
                            int nf = *s.begin();
                            indPrefix[nf] = 1;
                            rangeAddPrefix(nf, 1);
                        }
                    }
                    if (wasLast) {
                        indSuffix[idx] = 0;
                        rangeAddSuffix(idx, -1);
                        if (!s.empty()) {
                            int nl = *s.rbegin();
                            indSuffix[nl] = 1;
                            rangeAddSuffix(nl, 1);
                        }
                    }
                }

                nums[idx] = val;

                if (isPrime[val]) {
                    auto& s = pos[val];
                    s.insert(idx);
                    if (*s.begin() == idx) {
                        indPrefix[idx] = 1;
                        rangeAddPrefix(idx, 1);
                        if (s.size() > 1) {
                            auto it = s.begin(); ++it;
                            int of = *it;
                            indPrefix[of] = 0;
                            rangeAddPrefix(of, -1);
                        }
                    }
                    if (*s.rbegin() == idx) {
                        indSuffix[idx] = 1;
                        rangeAddSuffix(idx, 1);
                        if (s.size() > 1) {
                            auto it = s.rbegin(); ++it;
                            int ol = *it;
                            indSuffix[ol] = 0;
                            rangeAddSuffix(ol, -1);
                        }
                    }
                }
            }

            ans.push_back(seg[1]);
        }

        return ans;
    }
};
