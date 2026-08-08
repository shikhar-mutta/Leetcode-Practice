// Link: https://leetcode.com/problems/path-with-maximum-minimum-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        priority_queue<array<int,3>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!pq.empty()) {
            auto [val, r, c] = pq.top(); pq.pop();
            if (r == rows - 1 && c == cols - 1) return val;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                pq.push({min(val, grid[nr][nc]), nr, nc});
            }
        }
        return -1;
    }
};
