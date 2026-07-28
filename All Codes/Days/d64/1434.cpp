// Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int MOD = 1e9 + 7;
        int n = hats.size();
        vector<vector<int>> byHat(41);
        for (int i = 0; i < n; i++)
            for (int h : hats[i]) byHat[h].push_back(i);
        vector<vector<int>> dp(41, vector<int>(1 << n, 0));
        dp[0][0] = 1;
        for (int h = 1; h <= 40; h++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[h][mask] = dp[h - 1][mask];
                for (int p : byHat[h]) {
                    if (mask & (1 << p))
                        dp[h][mask] = (dp[h][mask] + dp[h - 1][mask ^ (1 << p)]) % MOD;
                }
            }
        }
        return dp[40][(1 << n) - 1];
    }
};
