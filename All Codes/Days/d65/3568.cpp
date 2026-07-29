// Link: https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterPos;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') {
                    litterIdx[i][j] = litterPos.size();
                    litterPos.push_back({i, j});
                }
            }
        }

        int L = litterPos.size();
        int fullMask = (1 << L) - 1;

        // 4D visited: [row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << L, false))));

        int startMask = 0;
        if (litterIdx[sr][sc] != -1) startMask |= (1 << litterIdx[sr][sc]);

        if (startMask == fullMask) return 0;

        queue<tuple<int,int,int,int>> q;
        q.push({sr, sc, energy, startMask});
        visited[sr][sc][energy][startMask] = true;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            moves++;
            for (int t = 0; t < sz; t++) {
                auto [r, c, e, mask] = q.front(); q.pop();
                if (e == 0) continue; // stuck unless was reset at arrival (already handled)

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int ne = e - 1;
                    int nmask = mask;
                    if (litterIdx[nr][nc] != -1) nmask |= (1 << litterIdx[nr][nc]);
                    if (classroom[nr][nc] == 'R') ne = energy;

                    if (nmask == fullMask) return moves;

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
        }

        return -1;
    }
};
