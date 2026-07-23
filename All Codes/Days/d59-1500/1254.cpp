// Link: https://leetcode.com/problems/number-of-closed-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static inline const int dir[5] = {0, 1, 0, -1, 0};

public:
    // TC: O(m * n) where m is the number of rows and n is the number of columns in the grid
    // SC: O(m * n) for the recursion stack in the worst case
    //    Approach:
    //     1. We will use a depth-first search (DFS) to traverse the grid and find the closed islands. A closed island is defined as a group of connected 0s (land) that is completely surrounded by 1s (water) and does not touch the boundary of the grid.
    //     2. We will iterate through each cell in the grid.
    //     3. If we find a cell with value 0, we will call the DFS function to explore the island starting from that cell.
    //     4. The DFS function will mark the visited cells by changing their value to 1 and will return true if the island is closed (does not touch the boundary) and false otherwise.
    //     5. We will keep a count of the number of closed islands found during the iteration and return that count as the final result.

    int closedIsland(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // ask for if the cell && dfs is 0 (island)

                if (grid[i][j] == 0 && dfs(i, j, grid, m, n))
                {
                    islands++;
                }
            }
        }
        return islands;
    }
    bool dfs(int i, int j, vector<vector<int>> &grid, int m, int n)
    {
        // 1) return if out of bound
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        // 2) return if is water
        if (grid[i][j] == 1)
            return 1;

        // 3) mark as visited
        grid[i][j] = 1;
        bool vis = 1;

        // 4) dfs 4 directions
        for (int d = 0; d < 4; d++)
        {
            int nr = i + dir[d], nc = j + dir[d + 1];
            vis &= dfs(nr, nc, grid, m, n);
        }
        return vis;
    }
};