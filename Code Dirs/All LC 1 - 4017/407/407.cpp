// Link: https://leetcode.com/problems/trapping-rain-water-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n log(m*n))  SC: O(m*n)
// Approach: min-heap starting from border cells; pop the lowest boundary
// cell, expand to unvisited neighbors trapping water up to max(current
// water level, neighbor height)
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int water = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!pq.empty()) {
            auto [h, r, c] = pq.top(); pq.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                water += max(0, h - heightMap[nr][nc]);
                pq.push({max(h, heightMap[nr][nc]), nr, nc});
            }
        }
        return water;
    }
};
