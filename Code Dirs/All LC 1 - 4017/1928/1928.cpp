// Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0});

        vector<vector<int>> best(n, vector<int>(maxTime + 1, INT_MAX));
        best[0][0] = passingFees[0];
        int ans = INT_MAX;

        while (!pq.empty()) {
            auto [cost, t, u] = pq.top(); pq.pop();
            if (cost > best[u][t]) continue;
            if (u == n - 1) ans = min(ans, cost);
            for (auto& [v, w] : adj[u]) {
                int nt = t + w;
                if (nt > maxTime) continue;
                int ncost = cost + passingFees[v];
                if (ncost < best[v][nt]) {
                    best[v][nt] = ncost;
                    pq.push({ncost, nt, v});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
