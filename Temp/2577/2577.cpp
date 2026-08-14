// Link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (t > dist[r][c]) continue;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int needed = grid[nr][nc];
                int arrive = t + 1;
                if (arrive < needed) {
                    int extra = needed - arrive;
                    if (extra % 2 == 0) arrive = needed;
                    else arrive = needed + 1;
                }
                if (arrive < dist[nr][nc]) {
                    dist[nr][nc] = arrive;
                    pq.push({arrive, nr, nc});
                }
            }
        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
    }
};
