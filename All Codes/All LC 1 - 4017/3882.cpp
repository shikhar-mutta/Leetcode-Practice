// Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC : O(M * N * Max_XOR)
    // SC : O(M * N * Max_XOR)
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        // dp[i][j][_xor] = true if we have already visited cell (i, j) with XOR value _xor
        vector dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        auto dfs = [&](auto &&dfs, int i, int j, int _xor) -> void
        {
            // out of bound OR already visited state with the same XOR value
            if (ans == 0 || i < 0 || j < 0 || dp[i][j][_xor])
                return;
            // base case (0, 0) cell
            if (i == 0 && j == 0) // reached the starting cell
            {
                ans = min(ans, _xor ^ grid[0][0]);
                return;
            }
            // reached cell-value
            dp[i][j][_xor] = true; // mark the current state as visited
            // recursion
            dfs(dfs, i - 1, j, _xor ^ grid[i][j]); // go up
            dfs(dfs, i, j - 1, _xor ^ grid[i][j]); // go left
        };
        // go backward
        dfs(dfs, m - 1, n - 1, 0);
        return ans;
    }
};