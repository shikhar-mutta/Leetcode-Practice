// Link: https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m), SC: O(n * m) (DFS recursion stack)
class Solution
{
public:
    int dRow[4] = {1, 0, -1, 0};
    int dCol[4] = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
        {
            int newRow = i + dRow[k];
            int newCol = j + dCol[k];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1)
            {
                dfs(newRow, newCol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Remove boundary-connected land
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);

            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid);

            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};
