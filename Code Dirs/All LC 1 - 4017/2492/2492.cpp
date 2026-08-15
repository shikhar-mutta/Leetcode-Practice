// Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int best = INT_MAX;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, w] : adj[u]) {
                best = min(best, w);
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return best;
    }
};
