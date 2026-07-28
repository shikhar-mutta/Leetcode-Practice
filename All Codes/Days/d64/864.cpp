// Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m*n*2^k)  SC: O(m*n*2^k)
// Approach: BFS over states (row, col, keyMask), starting from '@'.
// Walls block movement; locks require the matching key bit already in
// the mask; stepping on a key OR's its bit into the mask. The first
// time the mask has all key bits set gives the shortest path.
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sr = -1, sc = -1, numKeys = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') { sr = i; sc = j; }
                if (islower(grid[i][j])) numKeys++;
            }
        int fullMask = (1 << numKeys) - 1;

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << numKeys, false)));
        queue<tuple<int,int,int>> q;
        q.push({sr, sc, 0});
        visited[sr][sc][0] = true;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [x, y, mask] = q.front(); q.pop();
                if (mask == fullMask) return steps;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    char c = grid[nx][ny];
                    if (c == '#') continue;
                    int nmask = mask;
                    if (isupper(c) && !(mask & (1 << (c - 'A')))) continue; // locked
                    if (islower(c)) nmask |= (1 << (c - 'a'));
                    if (!visited[nx][ny][nmask]) {
                        visited[nx][ny][nmask] = true;
                        q.push({nx, ny, nmask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
