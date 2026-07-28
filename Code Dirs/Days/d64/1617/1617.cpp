// Link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(n - 1, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt < 2) continue;
            // BFS/DFS within mask, check connectivity + count edges
            int start = __builtin_ctz(mask);
            vector<int> dist(n, -1);
            dist[start] = 0;
            queue<int> q; q.push(start);
            int visited = 1, edgeCount = 0;
            int farthest = start;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!(mask & (1 << v))) continue;
                    edgeCount++;
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        visited++;
                        if (dist[v] > dist[farthest]) farthest = v;
                        q.push(v);
                    }
                }
            }
            edgeCount /= 2;
            if (visited != cnt || edgeCount != cnt - 1) continue; // not a valid tree subset
            // BFS again from farthest to get diameter
            vector<int> dist2(n, -1);
            dist2[farthest] = 0;
            queue<int> q2; q2.push(farthest);
            int diam = 0, far2 = farthest;
            while (!q2.empty()) {
                int u = q2.front(); q2.pop();
                for (int v : adj[u]) {
                    if (!(mask & (1 << v))) continue;
                    if (dist2[v] == -1) {
                        dist2[v] = dist2[u] + 1;
                        if (dist2[v] > diam) { diam = dist2[v]; far2 = v; }
                        q2.push(v);
                    }
                }
            }
            if (diam >= 1) res[diam - 1]++;
        }
        return res;
    }
};
