// Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m*n*k)  SC: O(m*n*k)
// Approach: BFS over states (row, col, obstaclesEliminatedSoFar). Moving
// into an obstacle consumes one elimination (only if remaining allows).
// If k is already large enough to eliminate every obstacle on any
// shortest Manhattan path, short-circuit with (m-1)+(n-1).
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 2) return m + n - 2;

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<tuple<int,int,int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = true;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [x, y, rem] = q.front(); q.pop();
                if (x == m - 1 && y == n - 1) return steps;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    int nrem = rem - grid[nx][ny];
                    if (nrem < 0) continue;
                    if (visited[nx][ny][nrem]) continue;
                    visited[nx][ny][nrem] = true;
                    q.push({nx, ny, nrem});
                }
            }
            steps++;
        }
        return -1;
    }
};
