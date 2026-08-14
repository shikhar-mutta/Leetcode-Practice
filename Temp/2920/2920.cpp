// Link: https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MAXH = 14;

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<long long>> memo(n, vector<long long>(MAXH + 1, -1));

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

        // process nodes in reverse BFS/DFS order (children before parents)
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            for (int h = MAXH; h >= 0; h--) {
                long long curVal = coins[u] >> h;
                long long way1 = curVal - k;
                long long way2 = curVal >> 1;
                int h2 = min(h + 1, MAXH);
                for (int v : adj[u]) {
                    if (v == parent[u]) continue;
                    way1 += memo[v][h];
                    way2 += memo[v][h2];
                }
                memo[u][h] = max(way1, way2);
            }
        }
        return (int)memo[0][0];
    }
};
