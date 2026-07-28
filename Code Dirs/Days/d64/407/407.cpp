// Link: https://leetcode.com/problems/trapping-rain-water-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m*n*log(m*n))  SC: O(m*n)
// Approach: min-heap Dijkstra-like flood fill starting from all boundary
// cells (water level = cell height). Repeatedly pop the lowest boundary
// cell, expand to unvisited neighbors, trapping water = max(0, level -
// neighborHeight), and push each neighbor with level = max(level, its height).
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        int water = 0;
        while (!pq.empty()) {
            auto [level, x, y] = pq.top(); pq.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                water += max(0, level - heightMap[nx][ny]);
                pq.push({max(level, heightMap[nx][ny]), nx, ny});
            }
        }
        return water;
    }
};
