// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n); // neighbor, needsFlip (1 if edge originally a->b in this direction)
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int count = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, flip] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count += flip;
                    q.push(v);
                }
            }
        }
        return count;
    }
};
