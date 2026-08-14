// Link: https://leetcode.com/problems/find-edges-in-shortest-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> distFrom0 = dijkstra(n, adj, 0);
        vector<long long> distFromEnd = dijkstra(n, adj, n-1);
        long long total = distFrom0[n-1];

        int m = edges.size();
        vector<bool> res(m, false);
        if (total == LLONG_MAX) return res;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (distFrom0[u] != LLONG_MAX && distFromEnd[v] != LLONG_MAX &&
                distFrom0[u] + w + distFromEnd[v] == total) res[i] = true;
            if (distFrom0[v] != LLONG_MAX && distFromEnd[u] != LLONG_MAX &&
                distFrom0[v] + w + distFromEnd[u] == total) res[i] = true;
        }
        return res;
    }
};
