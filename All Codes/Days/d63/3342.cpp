// Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*log(n*m)) SC: O(n*m)
// Approach: Dijkstra over state (row, col, parity) since move duration
// alternates 1,2,1,2... based on how many moves have been made so far.
// To enter a room you must wait until moveTime[r][c], so arrival =
// max(currentTime, moveTime[r][c]) + duration. Answer = min over parity
// of dist at the last cell.
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<array<long long,2>>> dist(n, vector<array<long long,2>>(m, {LLONG_MAX, LLONG_MAX}));
        dist[0][0][0] = 0;
        priority_queue<tuple<long long,int,int,int>, vector<tuple<long long,int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0, 0});
        int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [time, r, c, p] = pq.top(); pq.pop();
            if (time > dist[r][c][p]) continue;
            if (r == n - 1 && c == m - 1) return (int)time;
            int duration = (p == 0) ? 1 : 2;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                long long start = max(time, (long long)moveTime[nr][nc]);
                long long arrival = start + duration;
                int np = 1 - p;
                if (arrival < dist[nr][nc][np]) {
                    dist[nr][nc][np] = arrival;
                    pq.push({arrival, nr, nc, np});
                }
            }
        }
        return (int)min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};
