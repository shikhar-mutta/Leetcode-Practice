// Link: https://leetcode.com/problems/as-far-from-land-as-possible/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) q.push({i, j});

        if (q.empty() || (int)q.size() == n*n) return -1;

        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        int dist = -1;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] != 0) continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
        return dist;
    }
};
