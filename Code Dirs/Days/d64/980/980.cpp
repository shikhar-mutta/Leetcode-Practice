// Link: https://leetcode.com/problems/unique-paths-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(3^(m*n))  bounded by small grid size  SC: O(m*n) recursion depth
// Approach: backtracking DFS from the start cell, marking visited cells
// as obstacles temporarily. Count a path as valid only when it reaches
// the end cell having visited every empty cell exactly once (tracked
// via a remaining-cells counter).
class Solution {
    int m, n, ans = 0;
    void dfs(vector<vector<int>>& grid, int x, int y, int remaining) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) return;
        if (grid[x][y] == 2) {
            if (remaining == 0) ans++;
            return;
        }
        int orig = grid[x][y];
        int nextRemaining = (orig == 0) ? remaining - 1 : remaining;
        grid[x][y] = -1;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        for (int d = 0; d < 4; d++) dfs(grid, x + dx[d], y + dy[d], nextRemaining);
        grid[x][y] = orig;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int sx = 0, sy = 0, empties = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { sx = i; sy = j; }
                if (grid[i][j] == 0) empties++;
            }
        dfs(grid, sx, sy, empties);
        return ans;
    }
};
