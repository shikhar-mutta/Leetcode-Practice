// Link: https://leetcode.com/problems/max-area-of-island/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(M*N) where M is the number of rows and N is the number of columns in the grid. We visit each cell exactly once.
    // SC: O(M*N) in the worst case, where the grid is filled with land (1s), and we need to store all of them in the recursion stack.
    //  Approach:
    //  1. We use Depth-First Search (DFS) to explore the grid.
    //  2. We iterate through each cell in the grid. If we find a land cell (1), we initiate a DFS from that cell to calculate the area of the island.
    //  3. In the DFS function, we mark the current cell as visited (by setting it to 0) and recursively explore its four neighboring cells (up, down, left, right).
    //  4. We keep track of the maximum area encountered during the exploration and return it as the result.
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int best = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    best = max(best, dfs(grid, i, j));
                }
            }
        }
        return best;
    }
};
