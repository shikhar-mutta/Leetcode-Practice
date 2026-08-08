// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dr[] = {0, 0, 0, 1, -1};
        int dc[] = {0, 1, -1, 0, 0};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            for (int d = 1; d <= 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int cost = (grid[r][c] == d) ? 0 : 1;
                if (dist[r][c] + cost < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + cost;
                    if (cost == 0) dq.push_front({nr, nc});
                    else dq.push_back({nr, nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
