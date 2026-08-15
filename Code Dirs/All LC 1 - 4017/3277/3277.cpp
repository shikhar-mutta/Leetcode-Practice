// Link: https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) f[i][i] = nums[i];
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                f[l][r] = f[l][r-1] ^ f[l+1][r];
            }
        }

        // maxF[l][r] = max f[l][j] for j in [l,r]
        vector<vector<int>> maxF(n, vector<int>(n, 0));
        for (int l = 0; l < n; l++) {
            maxF[l][l] = f[l][l];
            for (int r = l + 1; r < n; r++) {
                maxF[l][r] = max(maxF[l][r-1], f[l][r]);
            }
        }

        // ans[l][r] = max subarray xor score within nums[l..r]
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int r = 0; r < n; r++) {
            for (int l = r; l >= 0; l--) {
                ans[l][r] = maxF[l][r];
                if (l + 1 <= r) ans[l][r] = max(ans[l][r], ans[l+1][r]);
            }
        }

        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries) res.push_back(ans[q[0]][q[1]]);
        return res;
    }
};
