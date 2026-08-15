// Link: https://leetcode.com/problems/maximum-path-score-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*k) SC: O(n*k)
//  Approach: DP over (row, col, cost used) tracking max score, where cost
//  of a cell is 1 for value 1 or 2 (0) for value 0, and score adds the
//  cell's value. Roll the row dimension to save space.
class Solution
{
    int solveRec(int i, int j, int k, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || k < 0)
            return INT_MIN;

        if (i == 0 && j == 0)
            return 0; // grid[0][0] == 0

        int top = grid[i][j] + solveRec(i - 1, j, k - (grid[i][j] != 0), grid);
        int left = grid[i][j] + solveRec(i, j - 1, k - (grid[i][j] != 0), grid);

        return max(top, left);
    }

    int solveMem(int i, int j, int k, vector<vector<int>> &grid,
                 vector<vector<vector<int>>> &dp)
    {
        if (i < 0 || j < 0 || k < 0)
            return INT_MIN;

        if (i == 0 && j == 0)
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int currentVal = grid[i][j];
        int cost = currentVal != 0;

        int top = solveMem(i - 1, j, k - cost, grid, dp);
        int left = solveMem(i, j - 1, k - cost, grid, dp);

        int best = max(top, left);

        return dp[i][j][k] = (best == INT_MIN) ? INT_MIN : best + currentVal;
    }

    int solveTab(int m, int n, int k, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1)));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l <= k; l++)
                {
                    if (i == 0 && j == 0)
                        continue;

                    int currentVal = grid[i][j];
                    int cost = currentVal != 0;

                    int top = (i && l >= cost) ? dp[i - 1][j][l - cost] : -1;
                    int left = (j && l >= cost) ? dp[i][j - 1][l - cost] : -1;

                    int best = max(top, left);
                    dp[i][j][l] = best < 0 ? -1 : best + currentVal;
                }
            }
        }

        return dp[m - 1][n - 1][k];
    }

    int solveTabOpt(int m, int n, int k, vector<vector<int>> &grid)
    {
        // dp[i][j][c] = max sum reaching (i,j) using exactly c non-zero cells
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int val = grid[i][j];
                int cost = val != 0;
                int maxC = min(k, i + j);

                for (int c = cost; c <= maxC; c++)
                {
                    int top = (i > 0) ? dp[i - 1][j][c - cost] : -1;
                    int left = (j > 0) ? dp[i][j - 1][c - cost] : -1;

                    int best = max(top, left);
                    dp[i][j][c] = best < 0 ? -1 : best + val;
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++)
            ans = max(ans, dp[m - 1][n - 1][c]);
        return ans;
    }

    int solveTabSO(int m, int n, int k, vector<vector<int>> &grid)
    {
        // find min non-zero cells on any path
        vector<int> mc(n + 1, 1e9);
        mc[1] = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mc[j + 1] = min(mc[j], mc[j + 1]) + (grid[i][j] != 0);
        if (mc[n] > k)
            return -1;

        k = min(k, m + n - 2);

        const short NEG = SHRT_MIN / 2;
        vector<vector<short>> dp(n + 1, vector<short>(k + 2, NEG));
        dp[1][1] = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = grid[i][j];
                int cost = (val != 0);
                int maxC = min(k, i + j);

                for (int c = maxC; c >= 0; c--)
                {
                    int f = c - cost + 1;
                    dp[j + 1][c + 1] = max(dp[j + 1][f], dp[j][f]) + val;
                }
            }
        }

        return *max_element(dp[n].begin(), dp[n].end());
    }

public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        k = min(k, m + n - 1);
        return solveTabSO(m, n, k, grid);
    }
};