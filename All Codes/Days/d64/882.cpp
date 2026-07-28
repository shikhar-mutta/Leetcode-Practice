// Link: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(E log E)  SC: O(E)
// Approach: Dijkstra on the original n nodes (edge weight = cnt+1, the
// subdivided length). Every original node reached within maxMoves counts
// fully. For each edge, count how many of its subdivided intermediate
// nodes are reachable from each endpoint (min(cnt, leftoverBudget)),
// capped so the two sides never double-count more than the edge's total
// subdivided node count.
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int,int>> adj;
        for (auto& e : edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, cnt] : adj[u]) {
                long long nd = d + cnt + 1;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int reachedNodes = 0;
        for (int i = 0; i < n; i++) if (dist[i] <= maxMoves) reachedNodes++;

        int reachedSubNodes = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long fromU = (dist[u] <= maxMoves) ? max(0LL, maxMoves - dist[u]) : 0;
            long long fromV = (dist[v] <= maxMoves) ? max(0LL, maxMoves - dist[v]) : 0;
            reachedSubNodes += (int)min((long long)cnt, fromU + fromV);
        }
        return reachedNodes + reachedSubNodes;
    }
};
