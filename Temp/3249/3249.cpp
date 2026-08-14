// Link: https://leetcode.com/problems/count-the-number-of-good-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> stk;
        stk.push_back(0);
        visited[0] = true;
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    stk.push_back(v);
                }
            }
        }

        vector<int> size(n, 1);
        int good = 0;
        vector<bool> isGood(n, true);
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            int childSize = -1;
            bool ok = true;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                size[u] += size[v];
                if (childSize == -1) childSize = size[v];
                else if (size[v] != childSize) ok = false;
            }
            isGood[u] = ok;
            if (ok) good++;
        }

        return good;
    }
};
