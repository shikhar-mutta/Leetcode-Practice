// Link: https://leetcode.com/problems/count-number-of-possible-root-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<long long> guessSet;
        for (auto &g : guesses) guessSet.insert((long long)g[0] * 100001 + g[1]);

        vector<int> parent(n, -1);
        vector<int> order;
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    st.push(v);
                }
            }
        }

        int baseCorrect = 0;
        for (int v : order) {
            if (parent[v] == -1) continue;
            int u = parent[v];
            if (guessSet.count((long long)u * 100001 + v)) baseCorrect++;
        }

        vector<int> correctCount(n, -1);
        correctCount[0] = baseCorrect;

        // reroot via order (order is a valid DFS preorder from root 0, so parent processed before child)
        for (int idx = 1; idx < (int)order.size(); idx++) {
            int v = order[idx];
            int u = parent[v];
            int cnt = correctCount[u];
            if (guessSet.count((long long)u * 100001 + v)) cnt--;
            if (guessSet.count((long long)v * 100001 + u)) cnt++;
            correctCount[v] = cnt;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) if (correctCount[i] >= k) ans++;
        return ans;
    }
};
