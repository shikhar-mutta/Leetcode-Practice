// Link: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> xorSub(n, 0), tin(n, 0), tout(n, 0);
        int timer = 0;
        // iterative DFS
        vector<int> stk = {0};
        vector<int> parent(n, -1);
        vector<int> order;
        vector<bool> visited(n, false);
        visited[0] = true;
        // first pass: get order and parent via BFS/DFS
        stk = {0};
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            order.push_back(u);
            tin[u] = timer++;
            for (int v : adj[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    stk.push_back(v);
                }
            }
        }
        // process in reverse order for subtree xor and tout
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            xorSub[u] ^= nums[u];
            if (parent[u] != -1) xorSub[parent[u]] ^= xorSub[u];
        }
        // tout: max tin in subtree; recompute via reverse order too
        vector<int> maxTin = tin;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (parent[u] != -1) maxTin[parent[u]] = max(maxTin[parent[u]], maxTin[u]);
        }
        tout = maxTin;

        int totalXor = xorSub[0];
        auto isAncestor = [&](int a, int b) {
            return tin[a] <= tin[b] && tout[b] <= tout[a];
        };

        int best = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int x1, x2, x3;
                if (isAncestor(u, v)) {
                    x1 = xorSub[v];
                    x2 = xorSub[u] ^ xorSub[v];
                    x3 = totalXor ^ xorSub[u];
                } else if (isAncestor(v, u)) {
                    x1 = xorSub[u];
                    x2 = xorSub[v] ^ xorSub[u];
                    x3 = totalXor ^ xorSub[v];
                } else {
                    x1 = xorSub[u];
                    x2 = xorSub[v];
                    x3 = totalXor ^ xorSub[u] ^ xorSub[v];
                }
                int mx = max({x1, x2, x3});
                int mn = min({x1, x2, x3});
                best = min(best, mx - mn);
            }
        }
        return best;
    }
};
