// Link: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const long long MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n + 1, LLONG_MAX);
        dist[n] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, n});
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

        vector<long long> memo(n + 1, -1);
        function<long long(int)> dfs = [&](int u) -> long long {
            if (u == n) return 1;
            if (memo[u] != -1) return memo[u];
            long long ways = 0;
            for (auto& [v, w] : adj[u]) {
                if (dist[v] < dist[u]) {
                    ways = (ways + dfs(v)) % MOD;
                }
            }
            memo[u] = ways;
            return ways;
        };
        return (int)dfs(1);
    }
};
