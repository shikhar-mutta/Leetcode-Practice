// Link: https://leetcode.com/problems/cat-and-mouse-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int R = grid.size(), C = grid[0].size();
        int foodR = -1, foodC = -1;
        int mouseR = -1, mouseC = -1, catR = -1, catC = -1;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 'F') { foodR = i; foodC = j; }
                else if (grid[i][j] == 'M') { mouseR = i; mouseC = j; }
                else if (grid[i][j] == 'C') { catR = i; catC = j; }
            }

        auto enc = [&](int mr, int mc, int cr, int cc, int turn) {
            return (((mr * C + mc) * R * C + (cr * C + cc)) * 2 + turn);
        };

        int N = R * C * R * C * 2;
        vector<int> color(N, 0); // 0 unknown, 1 mouse win, 2 cat win
        vector<int> degree(N, 0);

        int dx[5] = {0, 0, 0, 1, -1};
        int dy[5] = {0, 1, -1, 0, 0};

        auto validMoves = [&](int r, int c, int jump, int turn) {
            vector<pair<int,int>> res;
            res.push_back({r, c}); // stay
            for (int d = 1; d <= 4; d++) {
                for (int step = 1; step <= jump; step++) {
                    int nr = r + dx[d] * step, nc = c + dy[d] * step;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') break;
                    res.push_back({nr, nc});
                }
            }
            return res;
        };

        // compute degree for all states
        for (int mr = 0; mr < R; mr++) {
            if (grid[mr][0] == '#' && C > 0) {} // no-op just to keep structure
            for (int mc = 0; mc < C; mc++) {
                if (grid[mr][mc] == '#') continue;
                for (int cr = 0; cr < R; cr++) {
                    for (int cc = 0; cc < C; cc++) {
                        if (grid[cr][cc] == '#') continue;
                        for (int turn = 0; turn < 2; turn++) {
                            int st = enc(mr, mc, cr, cc, turn);
                            if (turn == 0) degree[st] = validMoves(mr, mc, mouseJump, 0).size();
                            else degree[st] = validMoves(cr, cc, catJump, 1).size();
                        }
                    }
                }
            }
        }

        queue<int> q;
        for (int mr = 0; mr < R; mr++) {
            for (int mc = 0; mc < C; mc++) {
                if (grid[mr][mc] == '#') continue;
                for (int cr = 0; cr < R; cr++) {
                    for (int cc = 0; cc < C; cc++) {
                        if (grid[cr][cc] == '#') continue;
                        for (int turn = 0; turn < 2; turn++) {
                            int st = enc(mr, mc, cr, cc, turn);
                            if (mr == cr && mc == cc) {
                                color[st] = 2; // cat wins
                                q.push(st);
                            } else if (mr == foodR && mc == foodC) {
                                color[st] = 1; // mouse wins
                                q.push(st);
                            }
                        }
                    }
                }
            }
        }

        // predecessor generation: for a state (mr,mc,cr,cc,turn) that just got resolved,
        // its predecessors are states with the opposite turn where the mover could have moved into this position.
        while (!q.empty()) {
            int st = q.front(); q.pop();
            int result = color[st];
            int turn = st % 2;
            int rest = st / 2;
            int catPos = rest % (R * C);
            int mousePos = rest / (R * C);
            int mr = mousePos / C, mc = mousePos % C;
            int cr = catPos / C, cc = catPos % C;

            int prevTurn = 1 - turn;
            // predecessor: prevTurn's mover was at some position, moved to (mr,mc) if prevTurn==0(mouse) matching current mr,mc
            // and cat/mouse pos not-moved stays same
            if (prevTurn == 0) {
                // mouse moved to (mr,mc) from some (pr,pc); cat position cr,cc unchanged
                for (int pr = 0; pr < R; pr++) {
                    for (int pc = 0; pc < C; pc++) {
                        if (grid[pr][pc] == '#') continue;
                        auto moves = validMoves(pr, pc, mouseJump, 0);
                        bool can = false;
                        for (auto& mv : moves) if (mv.first == mr && mv.second == mc) { can = true; break; }
                        if (!can) continue;
                        int pst = enc(pr, pc, cr, cc, prevTurn);
                        if (color[pst] != 0) continue;
                        if (result == 1) {
                            color[pst] = 1;
                            q.push(pst);
                        } else {
                            degree[pst]--;
                            if (degree[pst] == 0) {
                                color[pst] = 2;
                                q.push(pst);
                            }
                        }
                    }
                }
            } else {
                // cat moved to (cr,cc) from some (pr,pc); mouse position unchanged
                for (int pr = 0; pr < R; pr++) {
                    for (int pc = 0; pc < C; pc++) {
                        if (grid[pr][pc] == '#') continue;
                        auto moves = validMoves(pr, pc, catJump, 1);
                        bool can = false;
                        for (auto& mv : moves) if (mv.first == cr && mv.second == cc) { can = true; break; }
                        if (!can) continue;
                        int pst = enc(mr, mc, pr, pc, prevTurn);
                        if (color[pst] != 0) continue;
                        if (result == 2) {
                            color[pst] = 2;
                            q.push(pst);
                        } else {
                            degree[pst]--;
                            if (degree[pst] == 0) {
                                color[pst] = 1;
                                q.push(pst);
                            }
                        }
                    }
                }
            }
        }

        int startState = enc(mouseR, mouseC, catR, catC, 0);
        return color[startState] == 1;
    }
};
