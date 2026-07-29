// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C), SC: O(R*C)
// Approach: 0-1 BFS (deque) — moving into empty cell costs 0, into obstacle costs 1.
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_back({0,0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!dq.empty()) {
            auto [r,c] = dq.front(); dq.pop_front();
            for (int k = 0; k < 4; k++) {
                int nr = r+dr[k], nc = c+dc[k];
                if (nr<0||nr>=R||nc<0||nc>=C) continue;
                int nd = dist[r][c] + grid[nr][nc];
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    if (grid[nr][nc] == 1) dq.push_back({nr,nc});
                    else dq.push_front({nr,nc});
                }
            }
        }
        return dist[R-1][C-1];
    }
};
