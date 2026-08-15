// Link: https://leetcode.com/problems/maximize-subarray-sum-after-removing-all-occurrences-of-one-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct SparseTable {
        vector<vector<long long>> st;
        vector<int> lg;
        void build(vector<long long>& a) {
            int n = a.size();
            int K = 1;
            while ((1 << K) <= n) K++;
            st.assign(K, vector<long long>(n));
            st[0] = a;
            for (int k = 1; k < K; k++)
                for (int i = 0; i + (1 << k) <= n; i++)
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            lg.assign(n + 1, 0);
            for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        }
        long long query(int l, int r) {
            int k = lg[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };

    long long maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> G(n + 1, 0);
        for (int i = 0; i < n; i++) G[i + 1] = G[i] + nums[i];
        SparseTable sp;
        sp.build(G);

        unordered_map<int, long long> g;
        unordered_map<int, int> lastTouch;
        long long f = 0;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            long long f_before = f;
            long long option1;
            auto it = lastTouch.find(x);
            if (it != lastTouch.end()) {
                int lt = it->second;
                if (lt + 1 <= i - 1) {
                    long long candidate = g[x] + (sp.query(lt + 1, i - 1) - G[lt + 1]);
                    ans = max(ans, candidate);
                }
                option1 = g[x] + (G[i] - G[lt + 1]);
            } else {
                option1 = LLONG_MIN / 2;
            }
            long long option2 = f_before;
            long long new_g = max(option1, option2);
            g[x] = new_g;
            lastTouch[x] = i;
            ans = max(ans, new_g);

            f = max((long long)nums[i], f + nums[i]);
            ans = max(ans, f);
        }
        for (auto& [x, lt] : lastTouch) {
            long long candidate;
            if (lt + 1 <= n) candidate = g[x] + (sp.query(lt + 1, n) - G[lt + 1]);
            else candidate = g[x];
            ans = max(ans, candidate);
        }
        return ans;
    }
};
