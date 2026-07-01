// Link: https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
            return;

        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
