// Link: https://leetcode.com/problems/modify-graph-edge-weights/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E^2 log V), SC: O(N+E)
// Approach: set every -1 edge to weight 1 first; if the shortest path is already > target,
// impossible (1 is the minimum weight). Otherwise process -1 edges one at a time: run Dijkstra,
// and if the current shortest distance is still short of target, bump just this edge's weight by
// the shortfall so the shortest path grows to exactly target, then stop early once achieved.
class Solution {
public:
    int n;
    vector<vector<int>> adjList; // stores edge indices per node

    long long dijkstra(vector<vector<int>>& edges, int src, int dst) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            if (e[2] == -1) continue;
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) { dist[v] = nd; pq.push({nd, v}); }
            }
        }
        return dist[dst];
    }

    vector<vector<int>> modifiedGraphEdges(int n_, vector<vector<int>>& edges, int source, int destination, int target) {
        n = n_;
        vector<int> wasNegOne;
        for (int i = 0; i < (int)edges.size(); i++) {
            if (edges[i][2] == -1) { edges[i][2] = 1; wasNegOne.push_back(i); }
        }

        long long baseDist = dijkstra(edges, source, destination);
        if (baseDist > target) return {};

        for (int idx : wasNegOne) {
            long long cur = dijkstra(edges, source, destination);
            if (cur == target) break;
            if (cur < target) {
                edges[idx][2] += (int)(target - cur);
            }
        }

        long long finalDist = dijkstra(edges, source, destination);
        if (finalDist != target) return {};
        return edges;
    }
};
