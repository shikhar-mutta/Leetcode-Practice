// Link: https://leetcode.com/problems/coloring-a-border/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) SC: O(m*n)
    // Approach: DFS
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c,
             int origColor, vector<pair<int, int>> &borderCells)
    {
        visited[r][c] = true;
        int m = grid.size(), n = grid[0].size();
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        bool isBorder = false;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
            {
                isBorder = true;
                continue;
            }
            if (grid[nr][nc] != origColor)
            {
                isBorder = true;
                continue;
            }
            if (!visited[nr][nc])
                dfs(grid, visited, nr, nc, origColor, borderCells);
        }
        if (isBorder)
            borderCells.push_back({r, c});
    }

    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> borderCells;
        dfs(grid, visited, row, col, grid[row][col], borderCells);

        for (auto &[r, c] : borderCells)
            grid[r][c] = color;
        return grid;
    }
};
