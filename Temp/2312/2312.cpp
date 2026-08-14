// Link: https://leetcode.com/problems/selling-pieces-of-wood/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> price(m + 1, vector<long long>(n + 1, 0));
        for (auto& p : prices) price[p[0]][p[1]] = p[2];

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int h = 1; h <= m; h++) {
            for (int w = 1; w <= n; w++) {
                long long best = price[h][w];
                for (int k = 1; k < w; k++) best = max(best, dp[h][k] + dp[h][w - k]);
                for (int k = 1; k < h; k++) best = max(best, dp[k][w] + dp[h - k][w]);
                dp[h][w] = best;
            }
        }
        return dp[m][n];
    }
};
