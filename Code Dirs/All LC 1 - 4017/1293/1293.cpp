// Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        k = min(k, m + n - 2);
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<tuple<int,int,int,int>> q; // r, c, remaining k, dist
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;
        int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};
        while (!q.empty()) {
            auto [r, c, rem, dist] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int nrem = rem - grid[nr][nc];
                if (nrem < 0 || visited[nr][nc][nrem]) continue;
                if (nr == m - 1 && nc == n - 1) return dist + 1;
                visited[nr][nc][nrem] = true;
                q.push({nr, nc, nrem, dist + 1});
            }
        }
        return -1;
    }
};
