// Link: https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
// Approach: For each candidate root i, DFS down each of its subtrees
// counting nodes whose distance from i is divisible by signalSpeed. Pairs
// of connectable servers routed through i must lie in different subtrees,
// so sum over unordered pairs of subtree counts (total*cnt - cnt^2 per
// subtree, halved) gives ans[i].
class Solution {
public:
    int dfs(int node, int par, int dist, vector<vector<pair<int, int>>>& adj,
            int signalSpeed) {
        int n = adj.size();
        int ans = 0;
        if (dist % signalSpeed == 0)
            ans++;
        for (auto it : adj[node]) {
            if (it.first == par)
                continue;
            ans += dfs(it.first, node, dist + it.second, adj, signalSpeed);
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                               int signalSpeed) {
        int n = edges.size();
        n++;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (adj[i].size() <= 1) {
                ans[i] = 0;
                continue;
            }
            vector<int> cnts;
            for (auto it : adj[i]) {
                int cnt = dfs(it.first, i, it.second, adj, signalSpeed);
                if (cnt > 0)
                    cnts.push_back(cnt);
            }
            int x = 0;
            if (cnts.size() >= 2) {
                int total = accumulate(cnts.begin(), cnts.end(), 0);
                for (auto it : cnts) {
                    x += (it * (total - it));
                }
                ans[i] = x / 2;
            } else
                ans[i] = 0;
        }
        return ans;
    }
};
