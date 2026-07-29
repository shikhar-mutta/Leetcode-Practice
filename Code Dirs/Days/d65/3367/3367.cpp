// Link: https://leetcode.com/problems/maximize-sum-of-weights-after-edge-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: root the tree. dp[u][0] = best subtree sum with u NOT connected to its parent (u has
// k slots free for children); dp[u][1] = best sum with u connected to its parent (k-1 slots
// free). For each child c via edge weight w, "not connecting" contributes dp[c][0]; "connecting"
// contributes dp[c][1]+w — the gain of connecting is the difference. dp[u][s] = sum of all
// children's "not connecting" baseline plus the top (k-s) positive gains. Answer = dp[root][0].
class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> parent(n, -1), order;
        vector<bool> visited(n, false);
        queue<int> q; q.push(0); visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (auto& [v, w] : adj[u]) if (!visited[v]) { visited[v] = true; parent[v] = u; q.push(v); }
        }

        vector<long long> dp0(n, 0), dp1(n, 0);
        for (int i = (int)order.size()-1; i >= 0; i--) {
            int u = order[i];
            long long base = 0;
            vector<long long> gains;
            for (auto& [v, w] : adj[u]) {
                if (v == parent[u]) continue;
                base += dp0[v];
                long long gain = (dp1[v] + w) - dp0[v];
                if (gain > 0) gains.push_back(gain);
            }
            sort(gains.begin(), gains.end(), greater<long long>());

            long long sum0 = base, sum1 = base;
            for (int t = 0; t < (int)gains.size(); t++) {
                if (t < k) sum0 += gains[t];
                if (t < k-1) sum1 += gains[t];
            }
            dp0[u] = sum0;
            dp1[u] = sum1;
        }

        return dp0[0];
    }
};
