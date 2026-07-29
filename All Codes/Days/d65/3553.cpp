// Link: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;

        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<long long> distRoot(n, 0);
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;
        up[0][0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, w] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    up[0][v] = u;
                    depth[v] = depth[u] + 1;
                    distRoot[v] = distRoot[u] + w;
                    q.push(v);
                }
            }
        }

        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k-1][up[k-1][v]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k)) u = up[k][u];
            if (u == v) return u;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return up[0][u];
        };

        auto dist = [&](int u, int v) {
            int l = lca(u, v);
            return distRoot[u] + distRoot[v] - 2 * distRoot[l];
        };

        vector<int> ans;
        for (auto& qr : queries) {
            int s1 = qr[0], s2 = qr[1], d = qr[2];
            long long total = dist(s1, s2) + dist(s2, d) + dist(s1, d);
            ans.push_back((int)(total / 2));
        }
        return ans;
    }
};
