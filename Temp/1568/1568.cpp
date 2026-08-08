// Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto [r, c] = q.front(); q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d], nc = c + dc[d];
                            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                            if (grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (countIslands(grid) != 1) return 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int c = countIslands(grid);
                    grid[i][j] = 1;
                    if (c != 1) return 1;
                }
            }
        }
        return 2;
    }
};
