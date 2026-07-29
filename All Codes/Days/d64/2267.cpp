// Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R * C * (R + C)) where R is the number of rows and C is the number of columns in the grid
// SC: O(R * C * (R + C)) where R is the number of rows and C is the number of columns in the grid
// Approach: We can use dynamic programming to solve this problem. We can create a 3D dp array where dp[i][j][b] represents whether there is a valid path from the top-left cell to the cell (i, j) with a balance of b. We can initialize the dp array with false and set dp[0][0][1] to true if the first cell is '('. Then, we can iterate through the grid and update the dp array based on the previous cells. Finally, we can return dp[R - 1][C - 1][0] which represents whether there is a valid path from the top-left cell to the bottom-right cell with a balance of 0.
class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        int R = grid.size(), C = grid[0].size();
        if ((R + C - 1) % 2 != 0)
            return false;
        int maxBal = R + C;
        vector<vector<vector<bool>>> dp(
            R, vector<vector<bool>>(C, vector<bool>(maxBal + 1, false)));
        auto delta = [&](int i, int j)
        { return grid[i][j] == '(' ? 1 : -1; };
        if (grid[0][0] == '(')
            dp[0][0][1] = true;
        else
            return false; // first char must be '(' for any valid path
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int d = delta(i, j);
                for (int b = 0; b <= maxBal; b++)
                {
                    bool from = false;
                    if (i > 0 && b - d >= 0 && b - d <= maxBal)
                        from = from || dp[i - 1][j][b - d];
                    if (j > 0 && b - d >= 0 && b - d <= maxBal)
                        from = from || dp[i][j - 1][b - d];
                    if (from)
                        dp[i][j][b] = true;
                }
            }
        }
        return dp[R - 1][C - 1][0];
    }
};
