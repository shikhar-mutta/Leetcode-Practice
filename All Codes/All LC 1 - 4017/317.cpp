// Link: https://leetcode.com/problems/shortest-distance-from-all-buildings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(b * m * n)  SC: O(m*n)
// Approach: BFS from every building, accumulate total distance and reachable
// count per empty cell; answer is min total distance among cells reached by all buildings
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> totalDist(m, vector<int>(n, 0));
        vector<vector<int>> reachCount(m, vector<int>(n, 0));
        int buildings = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                buildings++;
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                queue<tuple<int,int,int>> q;
                q.push({i, j, 0});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [r, c, d] = q.front(); q.pop();
                    for (auto& dir : dirs) {
                        int nr = r + dir[0], nc = c + dir[1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (visited[nr][nc] || grid[nr][nc] != 0) continue;
                        visited[nr][nc] = true;
                        totalDist[nr][nc] += d + 1;
                        reachCount[nr][nc]++;
                        q.push({nr, nc, d + 1});
                    }
                }
            }
        }

        int best = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reachCount[i][j] == buildings) {
                    if (best == -1 || totalDist[i][j] < best) best = totalDist[i][j];
                }
            }
        }
        return best;
    }
};
