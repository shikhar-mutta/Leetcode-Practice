// Link: https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) SC: O(V+E)
// Approach: Dijkstra's algorithm from node k; answer is the max shortest-path distance among all nodes, or -1 if any node is unreachable.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto& t : times) graph[t[0]].push_back({t[1], t[2]});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};
