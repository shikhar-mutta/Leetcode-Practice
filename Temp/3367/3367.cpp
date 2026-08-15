// Link: https://leetcode.com/problems/maximize-sum-of-weights-after-edge-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<pair<int,long long>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

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
                for (auto& [v, w] : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        stk.push_back(v);
                    }
                }
            }
        }

        vector<long long> dp0(n, 0), dp1(n, 0);
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            long long base = 0;
            vector<long long> benefits;
            for (auto& [v, w] : adj[u]) {
                if (v == parent[u]) continue;
                base += dp0[v];
                long long benefit = dp1[v] + w - dp0[v];
                benefits.push_back(benefit);
            }
            sort(benefits.rbegin(), benefits.rend());

            long long sum0 = base, sum1 = base;
            for (int i = 0; i < (int)benefits.size(); i++) {
                if (benefits[i] <= 0) break;
                if (i < k) sum0 += benefits[i];
                if (i < k - 1) sum1 += benefits[i];
            }
            dp0[u] = sum0;
            dp1[u] = sum1;
        }

        return dp0[0];
    }
};
