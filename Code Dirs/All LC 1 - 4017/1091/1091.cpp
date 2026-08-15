// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int dist = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1}, dc[] = {-1,0,1,-1,1,-1,0,1};
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                if (r == n-1 && c == n-1) return dist;
                for (int d = 0; d < 8; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] || grid[nr][nc] != 0) continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
        return -1;
    }
};
