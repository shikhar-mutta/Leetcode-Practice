// Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*m), SC: O(n*m)
// Approach:
// 1. Use dynamic programming to find the minimum path cost in the grid.
// 2. Create a dp array to store the minimum cost to reach each cell in the grid.
// 3. Iterate through each cell in the grid and calculate the minimum cost to reach that cell from the previous row, considering the move cost.
// 4. Return the minimum cost to reach any cell in the last row of the grid.
class Solution
{
public:
    int dyp(int i1, int i2, vector<vector<int>> &dp, vector<vector<int>> &a,
            vector<vector<int>> &c)
    {
        int n = a.size();
        int m = a[0].size();

        if (i1 == n - 1)
        {
            return a[n - 1][i2];
        }
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            int va = a[i1][i2];
            ans = min(ans, va + c[va][i] + dyp(i1 + 1, i, dp, a, c));
        }
        return dp[i1][i2] = ans;
    }
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans1 = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans1 = min(ans1, dyp(0, i, dp, grid, moveCost));
        }
        return ans1;
    }
};
