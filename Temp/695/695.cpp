// Link: https://leetcode.com/problems/max-area-of-island/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: DFS each unvisited land cell, sinking it and summing area; track max across all islands.
class Solution {
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r-1, c) + dfs(grid, r+1, c) + dfs(grid, r, c-1) + dfs(grid, r, c+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int best = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) best = max(best, dfs(grid, i, j));
        return best;
    }
};
