// Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<pair<int,int>>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) : n(n) {
        adj.assign(n, {});
        for (auto &e : edges) addEdge(e);
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            if (u == node2) return d;
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};
