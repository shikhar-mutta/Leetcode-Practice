// Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<array<int,2>>> dist(n, vector<array<int,2>>(m, {INT_MAX, INT_MAX}));
        dist[0][0][0] = 0;
        // state: 0=INT_MAX for [1]; use tuple (t,x,y,state)
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0, 0});
        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        while (!pq.empty()) {
            auto [t, x, y, state] = pq.top(); pq.pop();
            if (t > dist[x][y][state]) continue;
            int cost = (state == 0) ? 1 : 2;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nt = max(t, moveTime[nx][ny]) + cost;
                int nstate = 1 - state;
                if (nt < dist[nx][ny][nstate]) {
                    dist[nx][ny][nstate] = nt;
                    pq.push({nt, nx, ny, nstate});
                }
            }
        }
        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};
