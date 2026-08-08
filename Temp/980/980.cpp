// Link: https://leetcode.com/problems/unique-paths-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int sr = -1, sc = -1, empty = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) { sr = i; sc = j; }
                if (grid[i][j] == 0) empty++;
            }

        int paths = 0;
        function<void(int,int,int)> dfs = [&](int r, int c, int visited) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == -1) return;
            if (grid[r][c] == 2) {
                if (visited == empty + 1) paths++;
                return;
            }
            int orig = grid[r][c];
            grid[r][c] = -1;
            dfs(r+1, c, visited+1);
            dfs(r-1, c, visited+1);
            dfs(r, c+1, visited+1);
            dfs(r, c-1, visited+1);
            grid[r][c] = orig;
        };
        dfs(sr, sc, 0);
        return paths;
    }
};
