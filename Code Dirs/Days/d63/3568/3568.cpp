// Link: https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*energy*2^L) SC: O(m*n*energy*2^L)
// Approach: BFS over state (row, col, energyLeft, litterMask). Moving to
// an adjacent non-obstacle cell costs 1 energy, except landing on 'R'
// resets energy to full capacity. A move is only possible while energy >
// 0. Track which litter cells have been visited via a bitmask (<= 10
// litter cells). Since every move costs the same, plain BFS finds the
// minimum move count to reach a state with the full mask.
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') { sr = r; sc = c; }
                else if (classroom[r][c] == 'L') litter.push_back({r, c});
            }
        }
        int L = litter.size();
        int fullMask = (1 << L) - 1;
        auto bitOf = [&](int r, int c) -> int {
            for (int i = 0; i < L; i++) if (litter[i] == make_pair(r, c)) return i;
            return -1;
        };

        int startMask = 0;
        int b = bitOf(sr, sc);
        if (b != -1) startMask |= (1 << b);
        if (startMask == fullMask) return 0;

        // visited[r][c][e][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << L, false))));
        visited[sr][sc][energy][startMask] = true;

        queue<tuple<int,int,int,int,int>> q; // r,c,e,mask,steps
        q.push({sr, sc, energy, startMask, 0});
        int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};

        while (!q.empty()) {
            auto [r, c, e, mask, steps] = q.front(); q.pop();
            if (e == 0) continue;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;
                int nmask = mask;
                int nb = bitOf(nr, nc);
                if (nb != -1) nmask |= (1 << nb);
                if (visited[nr][nc][ne][nmask]) continue;
                visited[nr][nc][ne][nmask] = true;
                if (nmask == fullMask) return steps + 1;
                q.push({nr, nc, ne, nmask, steps + 1});
            }
        }
        return -1;
    }
};
