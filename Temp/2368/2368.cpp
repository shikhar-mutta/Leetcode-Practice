// Link: https://leetcode.com/problems/reachable-nodes-with-restrictions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> blocked(n, false);
        for (int r : restricted) blocked[r] = true;

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q; q.push(0);
        int count = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v] && !blocked[v]) {
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }
        return count;
    }
};
