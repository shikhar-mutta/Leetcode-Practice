// Link: https://leetcode.com/problems/shortest-path-to-get-food/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int sr = -1, sc = -1;
        for (int i = 0; i < rows && sr == -1; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == '*') { sr = i; sc = j; break; }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                if (grid[r][c] == '#') return dist;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                    if (visited[nr][nc] || grid[nr][nc] == 'X') continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
        return -1;
    }
};
