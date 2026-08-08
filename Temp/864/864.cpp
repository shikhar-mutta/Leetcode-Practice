// Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int sr = -1, sc = -1, allKeys = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                char c = grid[i][j];
                if (c == '@') { sr = i; sc = j; }
                if (c >= 'a' && c <= 'f') allKeys |= (1 << (c - 'a'));
            }

        vector<vector<vector<int>>> visited(rows, vector<vector<int>>(cols, vector<int>(1 << 6, 0)));
        queue<tuple<int,int,int,int>> q;
        q.push({sr, sc, 0, 0});
        visited[sr][sc][0] = 1;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!q.empty()) {
            auto [r, c, mask, d] = q.front(); q.pop();
            if (mask == allKeys) return d;
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                char ch = grid[nr][nc];
                if (ch == '#') continue;
                if (ch >= 'A' && ch <= 'F' && !(mask & (1 << (ch - 'A')))) continue;
                int nmask = mask;
                if (ch >= 'a' && ch <= 'f') nmask |= (1 << (ch - 'a'));
                if (visited[nr][nc][nmask]) continue;
                visited[nr][nc][nmask] = 1;
                q.push({nr, nc, nmask, d + 1});
            }
        }
        return -1;
    }
};
