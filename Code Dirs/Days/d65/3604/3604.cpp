// Link: https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,3>>> adj(n); // v, start, end
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2], e[3]});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, s, e] : adj[u]) {
                if (d > e) continue;
                long long arrive = max(d, (long long)s) + 1;
                if (arrive < dist[v]) {
                    dist[v] = arrive;
                    pq.push({arrive, v});
                }
            }
        }

        return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
    }
};
