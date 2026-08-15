// Link: https://leetcode.com/problems/tree-diameter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> bfs(int src, vector<vector<int>>& adj) {
        vector<int> dist(adj.size(), -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int farNode = src, farDist = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] > farDist) { farDist = dist[u]; farNode = u; }
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return {farNode, farDist};
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto [node, d1] = bfs(0, adj);
        auto [node2, diam] = bfs(node, adj);
        return diam;
    }
};
