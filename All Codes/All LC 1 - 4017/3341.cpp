// Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            auto [x, y] = pos;
            if (t > dist[x][y]) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nt = max(t, moveTime[nx][ny]) + 1;
                if (nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    pq.push({nt, {nx, ny}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};
