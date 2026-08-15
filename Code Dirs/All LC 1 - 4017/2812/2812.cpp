// Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) { dist[i][j] = 0; q.push({i,j}); }
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]==-1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        vector<vector<int>> safe(n, vector<int>(n, -1));
        priority_queue<tuple<int,int,int>> pq;
        pq.push({dist[0][0], 0, 0});
        safe[0][0] = dist[0][0];
        while (!pq.empty()) {
            auto [s, x, y] = pq.top(); pq.pop();
            if (s < safe[x][y]) continue;
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<n) {
                    int ns = min(s, dist[nx][ny]);
                    if (ns > safe[nx][ny]) {
                        safe[nx][ny] = ns;
                        pq.push({ns, nx, ny});
                    }
                }
            }
        }
        return safe[n-1][n-1];
    }
};
