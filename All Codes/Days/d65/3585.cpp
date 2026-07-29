// Link: https://leetcode.com/problems/find-weighted-median-node-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;

        vector<vector<pair<int,long long>>> adj(n);
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

        vector<int> ans;
        for (auto& qr : queries) {
            int u = qr[0], v = qr[1];
            if (u == v) { ans.push_back(u); continue; }
            int l = lca(u, v);
            long long T = distRoot[u] + distRoot[v] - 2 * distRoot[l];
            long long distU_L = distRoot[u] - distRoot[l];

            if (2 * distU_L >= T) {
                // answer within segment u -> lca
                int cur = u;
                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = up[k][cur];
                    if (depth[nxt] >= depth[l] && 2 * (distRoot[u] - distRoot[nxt]) < T) cur = nxt;
                }
                ans.push_back(up[0][cur]);
            } else {
                // answer within segment lca -> v, climb from v while condition holds
                int cur = v;
                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = up[k][cur];
                    if (depth[nxt] > depth[l] && 2 * (distU_L + distRoot[nxt] - distRoot[l]) >= T) cur = nxt;
                }
                ans.push_back(cur);
            }
        }

        return ans;
    }
};
