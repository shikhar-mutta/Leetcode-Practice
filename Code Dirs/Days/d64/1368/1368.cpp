// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m*n)  SC: O(m*n)
// Approach: 0-1 BFS using a deque. Moving in the direction the current
// cell's arrow already points costs 0 (push front); moving any other
// direction costs 1 (push back). This guarantees the deque stays sorted
// by distance, giving Dijkstra-like correctness at O(1) per edge.
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // direction encoding: 1=right,2=left,3=down,4=up
        int dx[5] = {0,0,0,1,-1}, dy[5] = {0,1,-1,0,0};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int d = 1; d <= 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int cost = (grid[x][y] == d) ? 0 : 1;
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
