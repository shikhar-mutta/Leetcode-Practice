// Link: https://leetcode.com/problems/path-with-maximum-gold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxi = 0;
    int n, m;
    void DFS(int row, int col, int sum, vector<vector<int>> &grid)
    {
        sum += grid[row][col];
        maxi = max(maxi, sum);

        int gold = grid[row][col];
        grid[row][col] = 0;

        if (row > 0 && grid[row - 1][col] != 0)
            DFS(row - 1, col, sum, grid);
        if (row < n - 1 && grid[row + 1][col] != 0)
            DFS(row + 1, col, sum, grid);
        if (col > 0 && grid[row][col - 1] != 0)
            DFS(row, col - 1, sum, grid);
        if (col < m - 1 && grid[row][col + 1] != 0)
            DFS(row, col + 1, sum, grid);

        grid[row][col] = gold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        int totalGold = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                totalGold += grid[i][j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    DFS(i, j, 0, grid);
                    if (totalGold == maxi)
                        return maxi;
                }
            }
        }
        return maxi;
    }
};