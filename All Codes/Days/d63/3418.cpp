// Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(m * n)
// Approach: DP over dp[i][j][k] = max money reaching (i,j) using k of the
// (at most 2) available "neutralize a negative cell to 0" powers. At each
// cell, either take it normally (carrying k forward) or, if k>0, spend one
// power to treat it as max(coins[i][j], 0).
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const long long NEG = LLONG_MIN / 2;
        vector<vector<array<long long,3>>> dp(m, vector<array<long long,3>>(n, {NEG, NEG, NEG}));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    long long best = NEG;
                    if (i == 0 && j == 0) {
                        best = coins[i][j];
                    } else {
                        if (i > 0) best = max(best, dp[i-1][j][k]);
                        if (j > 0) best = max(best, dp[i][j-1][k]);
                        if (best > NEG) best += coins[i][j];
                    }
                    if (k > 0) {
                        long long alt = NEG;
                        if (i == 0 && j == 0) {
                            alt = max(0, coins[i][j]);
                        } else {
                            if (i > 0) alt = max(alt, dp[i-1][j][k-1]);
                            if (j > 0) alt = max(alt, dp[i][j-1][k-1]);
                            if (alt > NEG) alt += max(coins[i][j], 0);
                        }
                        best = max(best, alt);
                    }
                    dp[i][j][k] = best;
                }
            }
        }
        return (int)dp[m-1][n-1][2];
    }
};
