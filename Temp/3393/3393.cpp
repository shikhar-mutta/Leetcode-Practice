// Link: https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        const int B = 16;
        if (k >= B) return 0;
        vector<vector<array<long long, B>>> dp(m, vector<array<long long, B>>(n));
        for (auto& row : dp) for (auto& a : row) a.fill(0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (i == 0 && j == 0) {
                    dp[i][j][v] = 1;
                    continue;
                }
                for (int x = 0; x < B; x++) {
                    long long ways = 0;
                    int prevX = x ^ v;
                    if (i > 0) ways += dp[i - 1][j][prevX];
                    if (j > 0) ways += dp[i][j - 1][prevX];
                    dp[i][j][x] = ways % MOD;
                }
            }
        }
        return (int)dp[m - 1][n - 1][k];
    }
};
