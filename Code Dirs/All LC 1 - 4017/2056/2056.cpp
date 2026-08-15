// Link: https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Move { int dx, dy, dist; };

    pair<int,int> posAt(int sx, int sy, const Move& m, int t) {
        int step = min(t, m.dist);
        return {sx + m.dx * step, sy + m.dy * step};
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<vector<int>> rookDirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> bishopDirs = {{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> queenDirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        vector<vector<Move>> options(n);
        for (int i = 0; i < n; i++) {
            vector<vector<int>>* dirs;
            if (pieces[i] == "rook") dirs = &rookDirs;
            else if (pieces[i] == "bishop") dirs = &bishopDirs;
            else dirs = &queenDirs;

            options[i].push_back({0, 0, 0});
            int sx = positions[i][0], sy = positions[i][1];
            for (auto& d : *dirs) {
                for (int dist = 1; dist <= 7; dist++) {
                    int nx = sx + d[0] * dist, ny = sy + d[1] * dist;
                    if (nx < 1 || nx > 8 || ny < 1 || ny > 8) break;
                    options[i].push_back({d[0], d[1], dist});
                }
            }
        }

        int count = 0;
        vector<Move> chosen(n);
        function<void(int)> backtrack = [&](int idx) {
            if (idx == n) { count++; return; }
            for (auto& mv : options[idx]) {
                bool ok = true;
                for (int t = 0; ok && t <= 7; t++) {
                    auto [px, py] = posAt(positions[idx][0], positions[idx][1], mv, t);
                    for (int j = 0; j < idx; j++) {
                        auto [qx, qy] = posAt(positions[j][0], positions[j][1], chosen[j], t);
                        if (px == qx && py == qy) { ok = false; break; }
                    }
                }
                if (ok) {
                    chosen[idx] = mv;
                    backtrack(idx + 1);
                }
            }
        };
        backtrack(0);
        return count;
    }
};
