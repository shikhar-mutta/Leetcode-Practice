// Link: https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N + Q log N), SC: O(N log N + N*26)
// Approach: binary lifting for LCA, plus root-to-node cumulative counts of each edge weight
// (1..26). For a query (u,v): path weight-count[w] = rootCnt[u][w] + rootCnt[v][w] -
// 2*rootCnt[lca][w]; path length via depth; answer = pathLength - max_w(pathCount[w])
// (turn everything into the already-most-common weight on the path).
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<vector<int>> rootCnt(n, vector<int>(27, 0));

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, w] : adj[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                rootCnt[v] = rootCnt[u];
                rootCnt[v][w]++;
                q.push(v);
            }
        }

        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j-1][up[j-1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++) if ((diff >> j) & 1) u = up[j][u];
            if (u == v) return u;
            for (int j = LOG-1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) { u = up[j][u]; v = up[j][v]; }
            }
            return up[0][u];
        };

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            int l = lca(u, v);
            int pathLen = depth[u] + depth[v] - 2*depth[l];
            int best = 0;
            for (int w = 1; w <= 26; w++) {
                int c = rootCnt[u][w] + rootCnt[v][w] - 2*rootCnt[l][w];
                best = max(best, c);
            }
            ans.push_back(pathLen - best);
        }
        return ans;
    }
};
