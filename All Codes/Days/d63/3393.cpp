// Link: https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * V) SC: O(m * n * V), V = xor-value range (32)
// Approach: DP over dp[i][j][x] = number of right/down paths from (0,0)
// to (i,j) whose cumulative XOR equals x. Transition combines the ways
// coming from above and from the left, XOR-ing in grid[i][j]. Answer is
// dp[m-1][n-1][k].
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7, V = 32;
        int m = grid.size(), n = grid[0].size();
        array<long long,V> zero{};
        vector<vector<array<long long,V>>> dp(m, vector<array<long long,V>>(n, zero));

        dp[0][0][grid[0][0] % V] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                for (int x = 0; x < V; x++) {
                    long long ways = 0;
                    int prevXor = x ^ grid[i][j];
                    if (i > 0) ways += dp[i-1][j][prevXor];
                    if (j > 0) ways += dp[i][j-1][prevXor];
                    dp[i][j][x] = ways % MOD;
                }
            }
        }
        return (int)dp[m-1][n-1][k % V];
    }
};
