// Link: https://leetcode.com/problems/minimum-increments-to-equalize-leaf-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<long long> value(n, 0);
        vector<long long> fixCount(n, 0);

        vector<int> parent(n, -1), order;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<vector<int>> children(n);
        for (int u = 0; u < n; u++) if (parent[u] != -1) children[parent[u]].push_back(u);

        // process in reverse BFS order = post-order for tree
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            if (children[u].empty()) {
                value[u] = cost[u];
                fixCount[u] = 0;
                continue;
            }
            unordered_map<long long,int> freq;
            long long bestVal = -1;
            int bestCount = -1;
            long long sumFix = 0;
            for (int c : children[u]) {
                sumFix += fixCount[c];
                int f = ++freq[value[c]];
                if (f > bestCount) { bestCount = f; bestVal = value[c]; }
            }
            int mismatches = (int)children[u].size() - bestCount;
            fixCount[u] = sumFix + mismatches;
            value[u] = bestVal + cost[u];
        }

        return (int)fixCount[0];
    }
};
