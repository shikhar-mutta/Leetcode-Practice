// Link: https://leetcode.com/problems/coloring-a-border/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int rows = grid.size(), cols = grid[0].size();
        int origColor = grid[row][col];
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int,int>> border;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        function<void(int,int)> dfs = [&](int r, int c) {
            visited[r][c] = true;
            bool isBorder = false;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) { isBorder = true; continue; }
                if (grid[nr][nc] != origColor) { isBorder = true; continue; }
                if (!visited[nr][nc]) dfs(nr, nc);
            }
            if (isBorder) border.push_back({r, c});
        };
        dfs(row, col);
        for (auto& [r, c] : border) grid[r][c] = color;
        return grid;
    }
};
