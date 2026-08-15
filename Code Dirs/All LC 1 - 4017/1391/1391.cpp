// Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // direction bits: RIGHT=1, LEFT=2, UP=4, DOWN=8
    unordered_map<int,int> streetDirs = {
        {1, 1|2}, // left-right
        {2, 4|8}, // up-down
        {3, 2|8}, // left-down
        {4, 1|8}, // right-down
        {5, 2|4}, // left-up
        {6, 1|4}  // right-up
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        int dirBit[] = {1, 2, 4, 8};
        int oppBit[] = {2, 1, 8, 4};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == m - 1 && c == n - 1) return true;
            int dirs = streetDirs[grid[r][c]];
            for (int d = 0; d < 4; d++) {
                if (!(dirs & dirBit[d])) continue;
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
                int nDirs = streetDirs[grid[nr][nc]];
                if (!(nDirs & oppBit[d])) continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return false;
    }
};
