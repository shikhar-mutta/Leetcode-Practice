// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int nd = dist[r][c] + grid[nr][nc];
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    if (grid[nr][nc] == 0) dq.push_front({nr, nc});
                    else dq.push_back({nr, nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
