// Link: https://leetcode.com/problems/dungeon-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(M*N) SC: O(M*N)
    // Approach:
    // 1. We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the minimum health needed to reach the princess from cell (i,j).
    // 2. We can initialize the last cell dp[m-1][n-1] to 1 if dungeon[m-1][n-1] is greater than or equal to 0, otherwise we can initialize it to 1 - dungeon[m-1][n-1].
    // 3. We can then iterate through the dungeon array in reverse order and calculate the minimum health needed for each cell based on the minimum health needed for the cells to the right and below it. We can use the formula dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]) to calculate the minimum health needed for each cell.
    // 4. Finally, we can return dp[0][0] as the minimum health needed to reach the princess from the starting cell (0,0).
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(1, need);
            }
        }
        return dp[0][0];
    }
};
