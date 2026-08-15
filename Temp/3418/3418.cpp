// Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const int NEG = INT_MIN / 2;
        vector<vector<array<int, 3>>> dp(m, vector<array<int, 3>>(n, {NEG, NEG, NEG}));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    int best = NEG;
                    // came from up or left, no neutralization used here
                    if (i > 0) best = max(best, dp[i - 1][j][k]);
                    if (j > 0) best = max(best, dp[i][j - 1][k]);
                    if (i == 0 && j == 0) best = 0;
                    if (best > NEG) best += coins[i][j];

                    // neutralize this cell (use one charge)
                    if (k > 0) {
                        int bestPrev = NEG;
                        if (i > 0) bestPrev = max(bestPrev, dp[i - 1][j][k - 1]);
                        if (j > 0) bestPrev = max(bestPrev, dp[i][j - 1][k - 1]);
                        if (i == 0 && j == 0) bestPrev = 0;
                        if (bestPrev > NEG) best = max(best, bestPrev);
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};
