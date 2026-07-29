// Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C*K), SC: O(R*C*K)
// Approach: dp[r][c][rem] = number of paths from (0,0) to (r,c) with path-sum % k == rem;
// transition from up/left cells with new remainder (rem + grid[r][c]) % k.
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int R = grid.size(), C = grid[0].size();
        const int MOD = 1e9+7;
        vector<vector<vector<long long>>> dp(R, vector<vector<long long>>(C, vector<long long>(k, 0)));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int v = grid[r][c] % k;
                if (r == 0 && c == 0) {
                    dp[r][c][v] = 1;
                    continue;
                }
                for (int rem = 0; rem < k; rem++) {
                    long long ways = 0;
                    int prev = ((rem - v) % k + k) % k;
                    if (r > 0) ways += dp[r-1][c][prev];
                    if (c > 0) ways += dp[r][c-1][prev];
                    dp[r][c][rem] = ways % MOD;
                }
            }
        }
        return (int)dp[R-1][C-1][0];
    }
};
