// Link: https://leetcode.com/problems/time-taken-to-mark-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto cost = [](int x) { return (x % 2 == 0) ? 2 : 1; };

        vector<int> parent(n, -1), order;
        order.reserve(n);
        {
            vector<int> stk;
            vector<bool> visited(n, false);
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
        }

        vector<long long> down(n, 0);
        vector<long long> best1(n, 0), best2(n, 0);
        vector<int> bestChild1(n, -1);

        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long val = down[v] + cost(v);
                if (val > best1[u]) {
                    best2[u] = best1[u];
                    best1[u] = val;
                    bestChild1[u] = v;
                } else if (val > best2[u]) {
                    best2[u] = val;
                }
            }
            down[u] = best1[u];
        }

        vector<long long> up(n, 0);
        // process in order (parent before child)
        for (int idx = 0; idx < (int)order.size(); idx++) {
            int u = order[idx];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long excludeVal = (bestChild1[u] == v) ? best2[u] : best1[u];
                long long candidate = max(up[u], excludeVal);
                up[v] = cost(u) + candidate;
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = (int)max(down[i], up[i]);
        }
        return res;
    }
};
