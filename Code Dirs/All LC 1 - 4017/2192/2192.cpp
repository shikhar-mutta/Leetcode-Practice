// Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);

        vector<set<int>> ancestors(n);
        for (int start = 0; start < n; start++) {
            vector<bool> visited(n, false);
            visited[start] = true;
            queue<int> q; q.push(start);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        ancestors[v].insert(start);
                        q.push(v);
                    }
                }
            }
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        return res;
    }
};
