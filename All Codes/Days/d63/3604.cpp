// Link: https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) SC: O(V + E)
// Approach: Dijkstra where an edge (u,v,start,end) is only usable if we
// arrive at u by time <= end; departure is max(arrivalTime, start), and
// traversal takes 1 unit, so relax dist[v] with max(dist[u],start)+1.
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,3>>> adj(n); // v, start, end
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2], e[3]});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [t, u] = pq.top(); pq.pop();
            if (t > dist[u]) continue;
            for (auto& [v, start, end] : adj[u]) {
                if (t > end) continue;
                int arrive = max(t, start) + 1;
                if (arrive < dist[v]) {
                    dist[v] = arrive;
                    pq.push({arrive, v});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};
