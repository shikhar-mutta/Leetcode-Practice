// Link: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(E log V)  SC: O(V+E)
// Approach: any valid subgraph must have a meeting node m where paths
// src1->m and src2->m converge, then a single shared path m->dest. Run
// Dijkstra from src1 and src2 on the forward graph, and Dijkstra from
// dest on the reverse graph. Answer = min over all m of
// dist1[m] + dist2[m] + distRev[m].
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n), radj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }
        auto dijkstra = [&](int src, vector<vector<pair<int,int>>>& g) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            dist[src] = 0;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto& [v, w] : g[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };
        vector<long long> d1 = dijkstra(src1, adj);
        vector<long long> d2 = dijkstra(src2, adj);
        vector<long long> d3 = dijkstra(dest, radj);
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || d3[i] == LLONG_MAX) continue;
            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};
