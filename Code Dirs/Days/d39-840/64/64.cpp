// Link: https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(n)
// Approach: 1D DP
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (j > 0)
                    dp[j] = min(dp[j], dp[j - 1]);
                dp[j] += grid[i][j];
            }
        return dp[n - 1];
    }
};