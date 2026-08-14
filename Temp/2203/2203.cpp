// Link: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pair<int,long long>>>& adj, int src) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,long long>>> fwd(n), rev(n);
        for (auto& e : edges) {
            fwd[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        auto dist1 = dijkstra(n, fwd, src1);
        auto dist2 = dijkstra(n, fwd, src2);
        auto distRev = dijkstra(n, rev, dest);

        long long best = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == LLONG_MAX || dist2[i] == LLONG_MAX || distRev[i] == LLONG_MAX) continue;
            long long total = dist1[i] + dist2[i] + distRev[i];
            if (best == -1 || total < best) best = total;
        }
        return best;
    }
};
