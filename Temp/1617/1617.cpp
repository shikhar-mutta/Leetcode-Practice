// Link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n - 1, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt < 2) continue;
            int start = __builtin_ctz(mask);
            vector<int> dist(n, -1);
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            int visited = 1;
            int maxDist = 0, farNode = start;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!(mask & (1 << v))) continue;
                    if (dist[v] != -1) continue;
                    dist[v] = dist[u] + 1;
                    if (dist[v] > maxDist) { maxDist = dist[v]; farNode = v; }
                    visited++;
                    q.push(v);
                }
            }
            if (visited != cnt) continue; // not connected
            // BFS again from farNode to get actual diameter
            vector<int> dist2(n, -1);
            dist2[farNode] = 0;
            queue<int> q2;
            q2.push(farNode);
            int diam = 0;
            while (!q2.empty()) {
                int u = q2.front(); q2.pop();
                for (int v : adj[u]) {
                    if (!(mask & (1 << v))) continue;
                    if (dist2[v] != -1) continue;
                    dist2[v] = dist2[u] + 1;
                    diam = max(diam, dist2[v]);
                    q2.push(v);
                }
            }
            if (diam >= 1) ans[diam - 1]++;
        }
        return ans;
    }
};
