// Link: https://leetcode.com/problems/number-of-distinct-islands/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: DFS each island recording the relative-path shape (sequence of directions taken including backtrack markers) as a canonical signature; count distinct signatures.
class Solution {
    int m, n;
    void dfs(vector<vector<int>>& grid, int r, int c, string& path, char dir) {
        if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return;
        grid[r][c] = 0;
        path += dir;
        dfs(grid, r-1, c, path, 'U');
        dfs(grid, r+1, c, path, 'D');
        dfs(grid, r, c-1, path, 'L');
        dfs(grid, r, c+1, path, 'R');
        path += 'B'; // backtrack marker to disambiguate shapes
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        unordered_set<string> shapes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    string path;
                    dfs(grid, i, j, path, 'S');
                    shapes.insert(path);
                }
            }
        }
        return shapes.size();
    }
};
