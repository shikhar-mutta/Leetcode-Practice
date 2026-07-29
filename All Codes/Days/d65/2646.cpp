// Link: https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*Trips + N), SC: O(N)
// Approach: for each trip, BFS to get the parent pointers from its start node, walk back from
// end to start marking a visit-count on each path node. Then tree DP (house-robber style): for
// each node choose halved/not-halved, no two adjacent both halved, minimizing total cost.
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> cnt;
    vector<int>* price;

    pair<long long,long long> dfs(int u, int parent) {
        long long notHalved = (long long)cnt[u] * (*price)[u];
        long long halved = (long long)cnt[u] * (*price)[u] / 2;
        for (int v : adj[u]) {
            if (v == parent) continue;
            auto [n0, n1] = dfs(v, u);
            notHalved += min(n0, n1);
            halved += n0;
        }
        return {notHalved, halved};
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price_, vector<vector<int>>& trips) {
        adj.assign(n, {});
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        cnt.assign(n, 0);
        price = &price_;

        for (auto& trip : trips) {
            int s = trip[0], e = trip[1];
            vector<int> parent(n, -2);
            parent[s] = -1;
            queue<int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == e) break;
                for (int v : adj[u]) if (parent[v] == -2) { parent[v] = u; q.push(v); }
            }
            int cur = e;
            while (cur != -1) { cnt[cur]++; cur = parent[cur]; }
        }

        auto [notHalved, halved] = dfs(0, -1);
        return (int)min(notHalved, halved);
    }
};
