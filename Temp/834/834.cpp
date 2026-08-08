// Link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> sz(n, 1), ans(n, 0);

        function<void(int,int)> dfs1 = [&](int u, int p) {
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs1(v, u);
                sz[u] += sz[v];
                ans[u] += ans[v] + sz[v];
            }
        };
        function<void(int,int)> dfs2 = [&](int u, int p) {
            for (int v : adj[u]) {
                if (v == p) continue;
                ans[v] = ans[u] - sz[v] + (n - sz[v]);
                dfs2(v, u);
            }
        };
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
