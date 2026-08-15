// Link: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        vector<int> deg(n + 1, 0);
        for (auto& e : edges) {
            adj[e[0]][e[1]] = adj[e[1]][e[0]] = true;
            deg[e[0]]++;
            deg[e[1]]++;
        }
        int best = INT_MAX;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            for (int w = 1; w <= n; w++) {
                if (adj[u][w] && adj[v][w]) {
                    best = min(best, deg[u] + deg[v] + deg[w] - 6);
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
