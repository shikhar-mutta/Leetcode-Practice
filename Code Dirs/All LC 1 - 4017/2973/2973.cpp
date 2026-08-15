// Link: https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1), order;
        vector<bool> vis(n, false);
        stack<int> st;
        st.push(0); vis[0] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) { vis[v] = true; parent[v] = u; st.push(v); }
            }
        }

        vector<long long> ans(n, 0);
        vector<long long> size(n, 0);
        vector<vector<long long>> reduced(n);

        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            vector<long long> merged;
            long long sz = 1;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                sz += size[v];
                for (long long x : reduced[v]) merged.push_back(x);
            }
            merged.push_back(cost[u]);
            sort(merged.begin(), merged.end());
            size[u] = sz;

            if (sz < 3) {
                ans[u] = 1;
            } else {
                int m = merged.size();
                long long best = merged[m-1] * merged[m-2] * merged[m-3];
                best = max(best, merged[0] * merged[1] * merged[m-1]);
                ans[u] = max(0LL, best);
            }

            vector<long long> red;
            int m = merged.size();
            if (m <= 5) red = merged;
            else {
                red.push_back(merged[0]);
                red.push_back(merged[1]);
                red.push_back(merged[m-3]);
                red.push_back(merged[m-2]);
                red.push_back(merged[m-1]);
            }
            reduced[u] = red;
        }
        return ans;
    }
};
