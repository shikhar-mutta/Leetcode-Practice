// Link: https://leetcode.com/problems/unique-paths-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^(m*n)) SC: O(m*n)
//  Approach: We can use a depth-first search (DFS) approach to solve this problem. We can start from the starting square and explore all possible paths to the ending square. We can keep track of the number of empty squares that we have visited and the number of empty squares that we still need to visit. If we reach the ending square and have visited all empty squares, we can increment the count of unique paths. We can also use backtracking to explore all possible paths and avoid revisiting squares that we have already visited. We can mark the squares that we have visited as -1 and restore them back to their original value after exploring all possible paths from that square.
class Solution
{
    int m, n, ans = 0;
    void dfs(vector<vector<int>> &grid, int x, int y, int remaining)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
            return;
        if (grid[x][y] == 2)
        {
            if (remaining == 0)
                ans++;
            return;
        }
        int orig = grid[x][y];
        int nextRemaining = (orig == 0) ? remaining - 1 : remaining;
        grid[x][y] = -1;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        for (int d = 0; d < 4; d++)
            dfs(grid, x + dx[d], y + dy[d], nextRemaining);
        grid[x][y] = orig;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int sx = 0, sy = 0, empties = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] == 0)
                    empties++;
            }
        dfs(grid, sx, sy, empties);
        return ans;
    }
};
