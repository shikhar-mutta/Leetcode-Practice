// Link: https://leetcode.com/problems/peaks-in-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long len = 0, badCount = 0, prefFree = 0, sufFree = 0;
        bool hasPeak = false;
    };

    int n;
    vector<int> P;
    vector<Node> tree;

    Node makeLeaf(int idx) {
        Node nd;
        nd.len = 1;
        nd.hasPeak = (P[idx] == 1);
        nd.prefFree = nd.hasPeak ? 0 : 1;
        nd.sufFree = nd.hasPeak ? 0 : 1;
        nd.badCount = 0;
        return nd;
    }

    Node merge(const Node& L, const Node& R) {
        Node nd;
        nd.len = L.len + R.len;
        nd.hasPeak = L.hasPeak || R.hasPeak;
        nd.prefFree = L.hasPeak ? L.prefFree : (L.len + R.prefFree);
        nd.sufFree = R.hasPeak ? R.sufFree : (R.len + L.sufFree);
        long long a = L.hasPeak ? (L.sufFree + 1) : L.len;
        long long b = R.hasPeak ? (R.prefFree + 1) : R.len;
        long long cross = a * b - 1;
        nd.badCount = L.badCount + R.badCount + cross;
        return nd;
    }

    void build(int node, int lo, int hi) {
        if (lo == hi) { tree[node] = makeLeaf(lo); return; }
        int mid = (lo + hi) / 2;
        build(2 * node, lo, mid);
        build(2 * node + 1, mid + 1, hi);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int lo, int hi, int idx) {
        if (lo == hi) { tree[node] = makeLeaf(lo); return; }
        int mid = (lo + hi) / 2;
        if (idx <= mid) update(2 * node, lo, mid, idx);
        else update(2 * node + 1, mid + 1, hi, idx);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int lo, int hi, int l, int r) {
        if (l <= lo && hi <= r) return tree[node];
        int mid = (lo + hi) / 2;
        if (r <= mid) return query(2 * node, lo, mid, l, r);
        if (l > mid) return query(2 * node + 1, mid + 1, hi, l, r);
        Node L = query(2 * node, lo, mid, l, r);
        Node R = query(2 * node + 1, mid + 1, hi, l, r);
        return merge(L, R);
    }

    bool isPeak(vector<int>& nums, int k) {
        if (k < 1 || k > n - 2) return false;
        return nums[k] > nums[k - 1] && nums[k] > nums[k + 1];
    }

    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        P.assign(n, 0);
        for (int k = 0; k < n; k++) P[k] = isPeak(nums, k) ? 1 : 0;
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                long long m = r - l + 1;
                if (m < 3) { ans.push_back(0); continue; }
                long long total = (m - 1) * (m - 2) / 2;
                Node res = query(1, 0, n - 1, l, r);
                ans.push_back(total - res.badCount);
            } else {
                int index = q[1], val = q[2];
                nums[index] = val;
                for (int k = index - 1; k <= index + 1; k++) {
                    if (k < 0 || k >= n) continue;
                    int newP = isPeak(nums, k) ? 1 : 0;
                    if (newP != P[k]) {
                        P[k] = newP;
                        update(1, 0, n - 1, k);
                    }
                }
            }
        }
        return ans;
    }
};
