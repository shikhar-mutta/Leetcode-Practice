// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || visited[i][j]) continue;
                int total = 0;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    total += grid[r][c];
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                best = max(best, total);
            }
        }
        return best;
    }
};
