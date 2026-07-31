// Link: https://leetcode.com/problems/cherry-pickup/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
//  Approach: simulate two people walking from (0,0) to (n-1,n-1)
//  simultaneously (equivalent to one round trip), so after `step` moves
//  each is at row x, col step-x. dp[x1][x2] = max cherries collectible
//  so far. Transition over the 4 combinations of (down/right) moves for
//  each person; cherries at a shared cell are only counted once.
class Solution
{
public:
    int dp[51][51][51];
    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int n)
    {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
        {
            return -1e5;
        }
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1]; // they will reach at the same time as
                                 // manhattan dist is same

        int cherry = 0;
        if (r1 == r2 && c1 == c2)
            cherry = grid[r1][c1];
        else
            cherry = grid[r1][c1] + grid[r2][c2];

        int DD = solve(grid, r1 + 1, c1, r2 + 1, n);
        int RR = solve(grid, r1, c1 + 1, r2, n);
        int DR = solve(grid, r1 + 1, c1, r2, n);
        int RD = solve(grid, r1, c1 + 1, r2 + 1, n);

        return dp[r1][c1][r2] = cherry + max(DD, max(RR, max(DR, RD)));
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] == -1 || grid[n - 1][n - 1] == -1)
        {
            return 0;
        }
        if (n == 1)
            return grid[0][0];
        memset(dp, -1e5, sizeof(dp));

        for (int r1 = 0; r1 < n; r1++)
        {
            for (int c1 = 0; c1 < n; c1++)
            {
                for (int r2 = 0; r2 < n; r2++)
                {
                    int c2 = r1 + c1 - r2;
                    if (c2 < 0 || c2 >= n)
                        continue;
                    if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
                        dp[r1][c1][r2] = grid[0][0];
                    else if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        dp[r1][c1][r2] = INT_MIN;

                    else
                    {
                        int cherry = 0;
                        if (r1 == r2 && c1 == c2)
                            cherry = grid[r1][c1];
                        else
                        {
                            cherry = grid[r1][c1] + grid[r2][c2];
                        }
                        int DD, RR, DR, RD;
                        DD = RR = DR = RD = INT_MIN;
                        if (r1 > 0 && r2 > 0)
                            DD = dp[r1 - 1][c1][r2 - 1];
                        if (c1 > 0 && c2 > 0)
                            RR = dp[r1][c1 - 1][r2];
                        if (r1 > 0 && c2 > 0)
                            DR = dp[r1 - 1][c1][r2];
                        if (c1 > 0 && r2 > 0)
                            RD = dp[r1][c1 - 1][r2 - 1];

                        dp[r1][c1][r2] = cherry + max(DD, max(RR, max(DR, RD)));
                    }
                }
            }
        }
        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};