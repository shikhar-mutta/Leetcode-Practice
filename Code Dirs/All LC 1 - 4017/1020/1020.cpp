// Link: https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) return;
            grid[r][c] = 0;
            dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1);
        };
        for (int i = 0; i < rows; i++) {
            dfs(i, 0);
            dfs(i, cols-1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j);
            dfs(rows-1, j);
        }
        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1) count++;
        return count;
    }
};
