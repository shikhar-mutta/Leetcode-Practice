// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                if (dist > 0 && (r == 0 || r == rows-1 || c == 0 || c == cols-1)) return dist;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                    if (visited[nr][nc] || maze[nr][nc] == '+') continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
        return -1;
    }
};
