// Link: https://leetcode.com/problems/shortest-bridge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1) return;
            grid[r][c] = 2;
            q.push({r, c});
            for (int d = 0; d < 4; d++) dfs(r + dr[d], c + dc[d]);
        };

        bool found = false;
        for (int i = 0; i < n && !found; i++)
            for (int j = 0; j < m && !found; j++)
                if (grid[i][j] == 1) { dfs(i, j); found = true; }

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (grid[nr][nc] == 1) return steps;
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
