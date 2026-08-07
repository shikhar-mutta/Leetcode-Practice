// Link: https://leetcode.com/problems/walls-and-gates/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: multi-source BFS from all gates simultaneously, filling in
// distances as the wave expands outward
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0) q.push({i, j});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (rooms[nr][nc] != INT_MAX) continue;
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
