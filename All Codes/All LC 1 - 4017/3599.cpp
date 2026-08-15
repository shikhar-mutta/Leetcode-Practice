// Link: https://leetcode.com/problems/partition-array-to-minimize-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] ^ nums[i];

        const int INF = INT_MAX;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int l = j - 1; l < i; l++) {
                    if (dp[j-1][l] == INF) continue;
                    int xorRange = pref[i] ^ pref[l];
                    int cand = max(dp[j-1][l], xorRange);
                    if (cand < dp[j][i]) dp[j][i] = cand;
                }
            }
        }

        return dp[k][n];
    }
};
