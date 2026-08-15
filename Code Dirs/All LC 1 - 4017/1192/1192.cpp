// Link: https://leetcode.com/problems/critical-connections-in-a-network/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, edgeId)
        for (int i = 0; i < (int)connections.size(); i++) {
            auto& c = connections[i];
            adj[c[0]].push_back({c[1], i});
            adj[c[1]].push_back({c[0], i});
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int parentEdge) {
            disc[u] = low[u] = timer++;
            for (auto& [v, edgeId] : adj[u]) {
                if (edgeId == parentEdge) continue;
                if (disc[v] == -1) {
                    dfs(v, edgeId);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) bridges.push_back({u, v});
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };
        dfs(0, -1);
        return bridges;
    }
};
