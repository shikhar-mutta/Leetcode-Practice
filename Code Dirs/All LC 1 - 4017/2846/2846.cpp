// Link: https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<vector<int>> cnt(n, vector<int>(27, 0));
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0); vis[0] = true; up[0][0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, w] : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    up[0][v] = u;
                    depth[v] = depth[u] + 1;
                    cnt[v] = cnt[u];
                    cnt[v][w]++;
                    q.push(v);
                }
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j-1][up[j-1][i]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j < LOG; j++)
                if ((diff >> j) & 1) a = up[j][a];
            if (a == b) return a;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) { a = up[j][a]; b = up[j][b]; }
            }
            return up[0][a];
        };

        vector<int> ans;
        for (auto& qu : queries) {
            int a = qu[0], b = qu[1];
            int l = lca(a, b);
            int len = depth[a] + depth[b] - 2 * depth[l];
            int maxFreq = 0;
            for (int w = 1; w <= 26; w++) {
                int total = cnt[a][w] + cnt[b][w] - 2 * cnt[l][w];
                maxFreq = max(maxFreq, total);
            }
            ans.push_back(len - maxFreq);
        }
        return ans;
    }
};
