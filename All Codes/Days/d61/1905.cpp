// Link: https://leetcode.com/problems/count-sub-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(n*m)
    //  Approach:
    //    1. We can use depth-first search (DFS) to traverse the grid and find all the islands in grid2.
    //    2. For each island in grid2, we can check if it is a sub-island of grid1 by checking if all the cells in the island are also present in grid1.
    //    3. If an island in grid2 is a sub-island of grid1, we can increment the count of sub-islands. Finally, we can return the count of sub-islands.
    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        if (grid1.size() == 0)
            return 0;

        int n = grid2.size(), m = grid2[0].size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] != 0)
                {
                    count += dfs(i, j, grid1, grid2);
                }
            }
        }
        return count;
    }

    bool dfs(int x, int y, vector<vector<int>> &grid1,
             vector<vector<int>> &grid2)
    {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, n = grid2.size(),
            m = grid2[0].size(), newx, newy;
        bool ans = true;

        if (grid1[x][y] == 0)
            ans = false;

        grid2[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            newx = x + dx[i];
            newy = y + dy[i];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m &&
                grid2[newx][newy] == 1)
            {
                ans = ans & dfs(newx, newy, grid1, grid2);
            }
        }

        return ans;
    }
};