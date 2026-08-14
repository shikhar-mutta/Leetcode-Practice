// Link: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int best = INT_MAX;
        for (int src = 0; src < n; src++) {
            vector<int> dist(n, -1), parent(n, -1);
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (v != parent[u]) {
                        best = min(best, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
