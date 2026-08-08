// Link: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                int nd = d + w + 1;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) if (dist[i] <= maxMoves) result++;

        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = dist[u] < maxMoves ? min(cnt, maxMoves - dist[u]) : 0;
            int b = dist[v] < maxMoves ? min(cnt, maxMoves - dist[v]) : 0;
            result += min(cnt, a + b);
        }
        return result;
    }
};
