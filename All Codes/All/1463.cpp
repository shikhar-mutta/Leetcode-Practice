// Link: https://leetcode.com/problems/cherry-pickup-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*m) SC: O(m*m)
//  Approach: Use dynamic programming to find the maximum number of cherries that can be collected by two robots. We can use a 2D dp array where dp[c1][c2] represents the maximum number of cherries that can be collected by the two robots when they are at columns c1 and c2 in the current row. We iterate through each row from bottom to top and update the dp array accordingly. Finally, we return dp[0][m-1] which represents the maximum number of cherries that can be collected by the two robots when they are at columns 0 and m-1 in the first row.
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dp[75][75] = {0};
        int next_dp[75][75] = {0};

        // Work from the bottom row up to row 0
        for (int r = n - 1; r >= 0; r--)
        {

            // PRUNING: Only calculate reachable columns for the current row
            int max_c1 = min(m - 1, r);
            int min_c2 = max(0, m - 1 - r);

            for (int c1 = 0; c1 <= max_c1; c1++)
            {
                for (int c2 = min_c2; c2 < m; c2++)
                {

                    int cherries = grid[r][c1];
                    if (c1 != c2)
                    {
                        cherries += grid[r][c2];
                    }

                    int max_next = 0;

                    // SMART BOUNDARIES: Eliminates the need for 'if' statements
                    // inside the loop
                    int start_d1 = max(0, c1 - 1);
                    int end_d1 = min(m - 1, c1 + 1);
                    int start_d2 = max(0, c2 - 1);
                    int end_d2 = min(m - 1, c2 + 1);

                    for (int d1 = start_d1; d1 <= end_d1; d1++)
                    {
                        for (int d2 = start_d2; d2 <= end_d2; d2++)
                        {
                            max_next = max(max_next, next_dp[d1][d2]);
                        }
                    }

                    dp[c1][c2] = cherries + max_next;
                }
            }
            // Copy calculated row into next_dp to prepare for the row above it.
            // memcpy is heavily optimized at the hardware level.
            memcpy(next_dp, dp, sizeof(dp));
        }

        return dp[0][m - 1];
    }
};
