// Link: https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long total = 0;
        for (int v : values) total += v;

        vector<int> order, parent(n, -1);
        vector<bool> vis(n, false);
        stack<int> st;
        st.push(0);
        vis[0] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    parent[v] = u;
                    st.push(v);
                }
            }
        }

        vector<long long> dp(n, 0);
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            bool isLeaf = true;
            long long childSum = 0;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                isLeaf = false;
                childSum += dp[v];
            }
            dp[u] = isLeaf ? values[u] : min((long long)values[u], childSum);
        }
        return total - dp[0];
    }
};
