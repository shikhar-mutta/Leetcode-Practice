// Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) SC: O(V + E)
// Approach: Dijkstra where each directed edge (u,v,w) can be traversed
// forward at cost w, or effectively reversed (v to u) at cost 2w.
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) { dist[v] = nd; pq.push({nd, v}); }
            }
        }
        return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
    }
};
