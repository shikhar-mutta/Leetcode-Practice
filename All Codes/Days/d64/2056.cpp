// Link: https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: exponential in candidates but bounded (n<=4 pieces, board 8x8)
// SC: O(candidates)
// Approach: generate every candidate move (direction, distance including 0)
// for each piece based on its type. Backtrack over one choice per piece,
// simulating turn-by-turn positions (a piece stops once it reaches its
// target) and rejecting any combination where two pieces ever occupy the
// same square at the same timestep.
class Solution {
    struct Move { int dr, dc, steps; };
    int n;
    vector<vector<int>> startPos;
    vector<vector<Move>> candidates;
    int ans = 0;

    bool simulate(vector<Move>& chosen) {
        int maxT = 0;
        for (auto& m : chosen) maxT = max(maxT, m.steps);
        for (int t = 1; t <= maxT; t++) {
            vector<pair<int,int>> pos;
            for (int i = 0; i < n; i++) {
                int s = min(t, chosen[i].steps);
                int r = startPos[i][0] + chosen[i].dr * s;
                int c = startPos[i][1] + chosen[i].dc * s;
                pos.push_back({r, c});
            }
            sort(pos.begin(), pos.end());
            for (int i = 1; i < n; i++) if (pos[i] == pos[i-1]) return false;
        }
        return true;
    }

    void backtrack(int idx, vector<Move>& chosen) {
        if (idx == n) {
            if (simulate(chosen)) ans++;
            return;
        }
        for (auto& m : candidates[idx]) {
            chosen.push_back(m);
            backtrack(idx + 1, chosen);
            chosen.pop_back();
        }
    }
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        n = pieces.size();
        startPos = positions;
        candidates.assign(n, {});
        vector<pair<int,int>> rookDirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<pair<int,int>> bishopDirs = {{1,1},{1,-1},{-1,1},{-1,-1}};
        for (int i = 0; i < n; i++) {
            candidates[i].push_back({0, 0, 0});
            vector<pair<int,int>> dirs;
            if (pieces[i] == "rook") dirs = rookDirs;
            else if (pieces[i] == "bishop") dirs = bishopDirs;
            else { dirs = rookDirs; for (auto& d : bishopDirs) dirs.push_back(d); }
            for (auto& [dr, dc] : dirs) {
                int r = positions[i][0], c = positions[i][1];
                int steps = 0;
                while (true) {
                    r += dr; c += dc;
                    if (r < 1 || r > 8 || c < 1 || c > 8) break;
                    steps++;
                    candidates[i].push_back({dr, dc, steps});
                }
            }
        }
        vector<Move> chosen;
        backtrack(0, chosen);
        return ans;
    }
};
