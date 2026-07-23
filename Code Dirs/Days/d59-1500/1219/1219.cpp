// Link: https://leetcode.com/problems/path-with-maximum-gold/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of rows and m is the number of columns in the grid.
// SC: O(n * m) for the recursion stack in the worst case, where n is the number of rows and m is the number of columns in the grid.
// Approach:
// 1. We will use a depth-first search (DFS) approach to explore all possible paths in the grid starting from each cell that contains gold (i.e., a positive integer).
// 2. For each cell, we will recursively explore its neighboring cells (up, down, left, right) that contain gold and have not been visited yet. We will keep track of the current sum of gold collected along the path and update the maximum gold collected so far.
// 3. We will mark the current cell as visited by setting its value to 0 before exploring its neighbors and restore its original value after the exploration is complete to allow for other paths to use it.
// 4. Finally, we will return the maximum gold collected from all possible paths in the grid.
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