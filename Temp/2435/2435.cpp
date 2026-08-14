// Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r = grid[i][j] % k;
                if (i == 0 && j == 0) {
                    dp[i][j][r] = 1;
                    continue;
                }
                for (int prevR = 0; prevR < k; prevR++) {
                    long long cnt = 0;
                    if (i > 0) cnt += dp[i-1][j][prevR];
                    if (j > 0) cnt += dp[i][j-1][prevR];
                    int newR = (prevR + r) % k;
                    dp[i][j][newR] = (dp[i][j][newR] + cnt) % MOD;
                }
            }
        }
        return (int)dp[m-1][n-1][0];
    }
};
