// Link: https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            if (d > dist[r][c]) continue;
            if (r == rows - 1 && c == cols - 1) return d;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                int nd = max(d, abs(heights[nr][nc] - heights[r][c]));
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }
        return dist[rows-1][cols-1];
    }
};
