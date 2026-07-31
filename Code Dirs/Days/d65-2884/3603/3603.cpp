// Link: https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1; // (1)*(1)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                long long best = LLONG_MAX;
                if (i > 0) {
                    long long fromCost = dp[i-1][j] + ((i-1 == 0 && j == 0) ? 0 : waitCost[i-1][j]);
                    best = min(best, fromCost);
                }
                if (j > 0) {
                    long long fromCost = dp[i][j-1] + ((i == 0 && j-1 == 0) ? 0 : waitCost[i][j-1]);
                    best = min(best, fromCost);
                }
                long long entryCost = (long long)(i + 1) * (j + 1);
                dp[i][j] = best + entryCost;
            }
        }

        return dp[m-1][n-1];
    }
};
