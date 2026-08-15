// Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        function<bool(int,int,int,int)> dfs = [&](int r, int c, int pr, int pc) -> bool {
            visited[r][c] = true;
            int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (nr == pr && nc == pc) continue;
                if (grid[nr][nc] != grid[r][c]) continue;
                if (visited[nr][nc]) return true;
                if (dfs(nr, nc, r, c)) return true;
            }
            return false;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
