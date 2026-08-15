// Link: https://leetcode.com/problems/cat-and-mouse-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<string> grid;
    int catJump, mouseJump;
    int foodR, foodC;
    int maxTurns;
    unordered_map<long long, int> memo;

    long long encode(int mr, int mc, int cr, int cc, int turn) {
        return (((((long long)mr * cols + mc) * rows + cr) * cols + cc) * (maxTurns + 1)) + turn;
    }

    bool dfs(int mr, int mc, int cr, int cc, int turn) {
        if (turn >= maxTurns) return false;
        if (mr == cr && mc == cc) return false;
        if (mr == foodR && mc == foodC) return true;
        if (cr == foodR && cc == foodC) return false;

        long long key = encode(mr, mc, cr, cc, turn);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        memo[key] = false;

        int dr[5] = {0, 0, 0, 1, -1};
        int dc[5] = {0, 1, -1, 0, 0};

        bool result;
        if (turn % 2 == 0) {
            result = false;
            for (int d = 0; d < 5 && !result; d++) {
                for (int step = 0; step <= mouseJump; step++) {
                    int nr = mr + dr[d] * step, nc = mc + dc[d] * step;
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#') break;
                    if (dfs(nr, nc, cr, cc, turn + 1)) { result = true; break; }
                }
            }
        } else {
            result = true;
            for (int d = 0; d < 5 && result; d++) {
                for (int step = 0; step <= catJump; step++) {
                    int nr = cr + dr[d] * step, nc = cc + dc[d] * step;
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#') break;
                    if (!dfs(mr, mc, nr, nc, turn + 1)) { result = false; break; }
                }
            }
        }
        memo[key] = result;
        return result;
    }

    bool canMouseWin(vector<string>& grid_, int catJump_, int mouseJump_) {
        grid = grid_;
        catJump = catJump_;
        mouseJump = mouseJump_;
        rows = grid.size();
        cols = grid[0].size();
        maxTurns = rows * cols * 2;

        int mr = 0, mc = 0, cr = 0, cc = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'M') { mr = i; mc = j; }
                else if (grid[i][j] == 'C') { cr = i; cc = j; }
                else if (grid[i][j] == 'F') { foodR = i; foodC = j; }
            }
        }
        return dfs(mr, mc, cr, cc, 0);
    }
};
