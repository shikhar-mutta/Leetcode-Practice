// Link: https://leetcode.com/problems/network-recovery-pathways/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n); // v, cost
        vector<int> indeg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
        }

        // topological order (Kahn's)
        vector<int> topo;
        queue<int> q;
        vector<int> deg = indeg;
        for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto& [v, c] : adj[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }

        vector<int> costs;
        for (auto& e : edges) costs.push_back(e[2]);
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        auto feasible = [&](int X) -> bool {
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == LLONG_MAX) continue;
                for (auto& [v, c] : adj[u]) {
                    if (c < X) continue;
                    if (!online[v]) continue;
                    if (dist[u] + c < dist[v]) dist[v] = dist[u] + c;
                }
            }
            return dist[n-1] != LLONG_MAX && dist[n-1] <= k;
        };

        if (costs.empty()) return -1;
        int lo = 0, hi = (int)costs.size() - 1;
        int best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasible(costs[mid])) { best = costs[mid]; lo = mid + 1; }
            else hi = mid - 1;
        }

        return best;
    }
};
