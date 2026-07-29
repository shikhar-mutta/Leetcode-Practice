// Link: https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: min path from any root is always the root alone (all prices positive), so answer for
// root u = (best downward path sum from u over the whole tree) - price[u]. Compute D[u] (best
// path sum strictly within u's subtree) bottom-up with top-2 child values tracked, then reroot
// top-down to get up[u] (best extension available through u's parent), combining both directions.
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        vector<int> parent(n, -1), order;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) if (!visited[v]) { visited[v] = true; parent[v] = u; q.push(v); }
        }

        vector<long long> D(n, 0), top1D(n, 0), top2D(n, 0), up(n, 0);
        vector<int> top1Child(n, -1);

        for (int i = (int)order.size()-1; i >= 0; i--) {
            int u = order[i];
            D[u] = price[u] + top1D[u];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                if (D[v] > top1D[u]) {
                    top2D[u] = top1D[u];
                    top1D[u] = D[v];
                    top1Child[u] = v;
                } else if (D[v] > top2D[u]) {
                    top2D[u] = D[v];
                }
            }
            D[u] = price[u] + top1D[u];
        }

        long long ans = 0;
        for (int u : order) ans = max(ans, max(top1D[u], up[u]));

        for (int u : order) {
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long childExclude = (top1Child[u] == v) ? top2D[u] : top1D[u];
                long long bestExcl = max(up[u], childExclude);
                up[v] = max(0LL, price[u] + bestExcl);
                ans = max(ans, up[v]);
            }
        }

        return ans;
    }
};
