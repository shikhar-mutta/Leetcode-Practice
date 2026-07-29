// Link: https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: build adjacency with a 0/1 cost per directed step (0 if traversing that direction
// matches the original edge, 1 if it needs a reversal). DFS from node 0 to get ans[0]. Then
// reroot: moving the root from u to neighbor v flips exactly one edge's relevance — ans[v] =
// ans[u] - cost(u->v) + cost(v->u) = ans[u] + (cost(u->v)==0 ? 1 : -1).
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, cost to go there)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], 0});
            adj[e[1]].push_back({e[0], 1});
        }

        vector<int> ans(n, 0);
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto& [v, c] : adj[u]) {
                if (visited[v]) continue;
                ans[0] += c;
                dfs(v);
            }
        };
        dfs(0);

        fill(visited.begin(), visited.end(), false);
        function<void(int)> reroot = [&](int u) {
            visited[u] = true;
            for (auto& [v, c] : adj[u]) {
                if (visited[v]) continue;
                ans[v] = ans[u] + (c == 0 ? 1 : -1);
                reroot(v);
            }
        };
        reroot(0);

        return ans;
    }
};
