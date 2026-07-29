// Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = edges.size() + 1;
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, 1));
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        up[0][1] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    up[0][v] = u;
                    q.push(v);
                }
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int v = 1; v <= n; v++)
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

        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) pow2[i] = (pow2[i-1] * 2) % MOD;

        vector<int> ans;
        for (auto& qr : queries) {
            int u = qr[0], v = qr[1];
            int l = lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[l];
            if (k == 0) ans.push_back(0);
            else ans.push_back((int)pow2[k-1]);
        }
        return ans;
    }
};
