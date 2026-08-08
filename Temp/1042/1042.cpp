// Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (auto& p : paths) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> color(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            vector<bool> used(5, false);
            for (int nb : adj[i]) used[color[nb]] = true;
            for (int c = 1; c <= 4; c++) {
                if (!used[c]) { color[i] = c; break; }
            }
        }
        return vector<int>(color.begin() + 1, color.end());
    }
};
