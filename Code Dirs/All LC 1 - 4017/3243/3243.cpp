// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i + 1 < n; i++) adj[i].push_back(i + 1);

        vector<int> res;
        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            vector<int> dist(n, -1);
            queue<int> bfs;
            dist[0] = 0;
            bfs.push(0);
            while (!bfs.empty()) {
                int u = bfs.front(); bfs.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        bfs.push(v);
                    }
                }
            }
            res.push_back(dist[n-1]);
        }
        return res;
    }
};
