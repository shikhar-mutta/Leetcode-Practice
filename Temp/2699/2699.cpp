// Link: https://leetcode.com/problems/modify-graph-edge-weights/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<long long> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj, vector<long long>& w) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, idx] : adj[u]) {
                long long nd = d + w[idx];
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist;
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int m = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }

        vector<long long> w(m);
        for (int i = 0; i < m; i++) w[i] = (edges[i][2] == -1) ? 1 : edges[i][2];

        auto initDist = dijkstra(source, n, adj, w);
        if (initDist[destination] > target) return {};

        if (initDist[destination] == target) {
            vector<vector<int>> res;
            for (int i = 0; i < m; i++) res.push_back({edges[i][0], edges[i][1], (int)w[i]});
            return res;
        }

        for (int i = 0; i < m; i++) {
            if (edges[i][2] != -1) continue;
            int u = edges[i][0], v = edges[i][1];

            auto distS = dijkstra(source, n, adj, w);
            auto distD = dijkstra(destination, n, adj, w);

            long long needed = LLONG_MIN;
            if (distS[u] != LLONG_MAX && distD[v] != LLONG_MAX) needed = max(needed, target - distS[u] - distD[v]);
            if (distS[v] != LLONG_MAX && distD[u] != LLONG_MAX) needed = max(needed, target - distS[v] - distD[u]);

            if (needed >= 1) {
                w[i] = needed;
                auto check = dijkstra(source, n, adj, w);
                if (check[destination] == target) {
                    vector<vector<int>> res;
                    for (int k = 0; k < m; k++) res.push_back({edges[k][0], edges[k][1], (int)w[k]});
                    return res;
                }
            }
        }

        return {};
    }
};
