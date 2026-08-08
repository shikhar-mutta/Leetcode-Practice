// Link: https://leetcode.com/problems/cat-and-mouse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        // state: (mouse, cat, turn) turn 0=mouse's move, 1=cat's move
        // result: 0=draw, 1=mouse wins, 2=cat wins
        vector<vector<vector<int>>> result(n, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int mouse = 0; mouse < n; mouse++)
            for (int cat = 0; cat < n; cat++) {
                degree[mouse][cat][0] = graph[mouse].size();
                degree[mouse][cat][1] = graph[cat].size();
                for (int nb : graph[cat]) if (nb == 0) degree[mouse][cat][1]--;
            }

        queue<tuple<int,int,int,int>> q;
        for (int cat = 1; cat < n; cat++) {
            for (int turn = 0; turn < 2; turn++) {
                result[0][cat][turn] = 1;
                q.push({0, cat, turn, 1});
            }
            result[cat][cat][0] = 2;
            result[cat][cat][1] = 2;
            q.push({cat, cat, 0, 2});
            q.push({cat, cat, 1, 2});
        }

        while (!q.empty()) {
            auto [mouse, cat, turn, res] = q.front(); q.pop();
            int prevTurn = 1 - turn;
            vector<pair<int,int>> preds;
            if (prevTurn == 0) {
                for (int m : graph[mouse]) preds.push_back({m, cat});
            } else {
                for (int c : graph[cat]) {
                    if (c == 0) continue;
                    preds.push_back({mouse, c});
                }
            }
            for (auto& [pm, pc] : preds) {
                if (result[pm][pc][prevTurn] != 0) continue;
                bool win = (prevTurn == 0 && res == 1) || (prevTurn == 1 && res == 2);
                if (win) {
                    result[pm][pc][prevTurn] = res;
                    q.push({pm, pc, prevTurn, res});
                } else {
                    degree[pm][pc][prevTurn]--;
                    if (degree[pm][pc][prevTurn] == 0) {
                        result[pm][pc][prevTurn] = prevTurn == 0 ? 2 : 1;
                        q.push({pm, pc, prevTurn, result[pm][pc][prevTurn]});
                    }
                }
            }
        }
        return result[1][2][0];
    }
};
