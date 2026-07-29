// Link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C log(R*C)), SC: O(R*C)
// Approach: Dijkstra where the "distance" is earliest arrival time. If a cell needs waiting
// (grid value > time+1), you can bounce back and forth on the previous edge to burn one extra
// time unit, so parity determines whether you wait exactly to grid value or grid value+1.
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            if (d > dist[r][c]) continue;
            for (int k = 0; k < 4; k++) {
                int nr = r+dr[k], nc = c+dc[k];
                if (nr<0||nr>=R||nc<0||nc>=C) continue;
                int cur = d + 1;
                if (cur < grid[nr][nc]) {
                    int diff = grid[nr][nc] - cur;
                    cur += diff % 2 == 0 ? diff : diff + 1;
                }
                if (cur < dist[nr][nc]) {
                    dist[nr][nc] = cur;
                    pq.push({cur, nr, nc});
                }
            }
        }
        return dist[R-1][C-1];
    }
};
