// Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: addEdge O(1), shortestPath O(E log V) via Dijkstra, SC: O(V+E)
// Approach: adjacency list of (neighbor, weight); addEdge just appends; shortestPath runs
// Dijkstra with a min-heap from the given source each call.
class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int n;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.assign(n, {});
        for (auto& e : edges) addEdge(e);
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<long long> dist(n, LLONG_MAX);
        dist[node1] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            if (u == node2) return (int)d;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) { dist[v] = nd; pq.push({nd, v}); }
            }
        }
        return dist[node2] == LLONG_MAX ? -1 : (int)dist[node2];
    }
};
