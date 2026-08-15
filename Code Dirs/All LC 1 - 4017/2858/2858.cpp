// Link: https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n); // {to, cost} cost=0 if forward, 1 if needs reversal
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], 0});
            adj[e[1]].push_back({e[0], 1});
        }
        vector<int> ans(n, 0);
        vector<bool> vis(n, false);
        stack<int> st;
        st.push(0);
        vis[0] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (auto& [v, c] : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    ans[0] += c;
                    st.push(v);
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        vis[0] = true;
        st.push(0);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (auto& [v, c] : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    ans[v] = ans[u] + (c == 0 ? 1 : -1);
                    st.push(v);
                }
            }
        }
        return ans;
    }
};
