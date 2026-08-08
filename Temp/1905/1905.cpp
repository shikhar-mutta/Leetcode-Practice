// Link: https://leetcode.com/problems/count-sub-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid2[r][c] == 0) return true;
        grid2[r][c] = 0;
        bool isSub = (grid1[r][c] == 1);
        bool d1 = dfs(grid1, grid2, r+1, c);
        bool d2 = dfs(grid1, grid2, r-1, c);
        bool d3 = dfs(grid1, grid2, r, c+1);
        bool d4 = dfs(grid1, grid2, r, c-1);
        return isSub && d1 && d2 && d3 && d4;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid2.size(); cols = grid2[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid2[r][c] == 1) {
                    if (dfs(grid1, grid2, r, c)) count++;
                }
            }
        }
        return count;
    }
};
