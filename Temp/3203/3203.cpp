// Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfsFarthest(vector<vector<int>>& adj, int src, int& farNode) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src); dist[src] = 0;
        int maxD = 0;
        farNode = src;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    if (dist[v] > maxD) { maxD = dist[v]; farNode = v; }
                    q.push(v);
                }
            }
        }
        return maxD;
    }

    int diameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n == 1) return 0;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int far;
        bfsFarthest(adj, 0, far);
        return bfsFarthest(adj, far, far);
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max({d1, d2, combined});
    }
};
