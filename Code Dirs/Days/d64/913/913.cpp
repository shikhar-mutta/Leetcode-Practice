// Link: https://leetcode.com/problems/cat-and-mouse/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^3)  SC: O(n^2)
// Approach: retrograde analysis (Zermelo's algorithm) over states
// (mousePos, catPos, turn). Terminal states (mouse at hole=0 -> mouse
// wins; mouse caught by cat -> cat wins) are seeded first, then
// propagated backward via BFS: a predecessor state is decided the
// moment either (a) it's that player's turn and one of the winning
// moves leads to their win, or (b) every possible move from it leads to
// the same loss (tracked via a remaining-degree counter). States never
// resolved after the BFS drains are draws.
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        // color[m][c][t]: 0=draw(unknown), 1=mouse wins, 2=cat wins
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int m = 0; m < n; m++)
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size();
                degree[m][c][1] = graph[c].size();
                for (int x : graph[c]) if (x == 0) { degree[m][c][1]--; break; }
            }

        queue<tuple<int,int,int,int>> q;
        for (int c = 1; c < n; c++)
            for (int t = 0; t < 2; t++) {
                color[0][c][t] = 1;
                q.push({0, c, t, 1});
                color[c][c][t] = 2;
                q.push({c, c, t, 2});
            }

        auto getPrevStates = [&](int m, int c, int t) {
            vector<tuple<int,int,int>> prevs;
            if (t == 0) {
                // current turn is mouse's; predecessor was cat's move (t=1) that led here with same mouse pos
                for (int pc : graph[c]) {
                    if (pc == 0) continue; // cat never at hole
                    prevs.push_back({m, pc, 1});
                }
            } else {
                // current turn is cat's; predecessor was mouse's move (t=0) that led here with same cat pos
                for (int pm : graph[m]) {
                    prevs.push_back({pm, c, 0});
                }
            }
            return prevs;
        };

        while (!q.empty()) {
            auto [m, c, t, result] = q.front(); q.pop();
            for (auto& [pm, pc, pt] : getPrevStates(m, c, t)) {
                if (color[pm][pc][pt] != 0) continue;
                bool win = (pt == 0 && result == 1) || (pt == 1 && result == 2);
                if (win) {
                    color[pm][pc][pt] = result;
                    q.push({pm, pc, pt, result});
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        int loseResult = (pt == 0) ? 2 : 1;
                        color[pm][pc][pt] = loseResult;
                        q.push({pm, pc, pt, loseResult});
                    }
                }
            }
        }
        return color[1][2][0];
    }
};
