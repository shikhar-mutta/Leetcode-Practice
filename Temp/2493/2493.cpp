// Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bfsDepth(int start, vector<vector<int>>& adj, int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int maxDepth = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    maxDepth = max(maxDepth, dist[v]);
                    q.push(v);
                }
            }
        }
        return maxDepth + 1;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(n + 1, -1);
        vector<int> compId(n + 1, -1);
        int numComp = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;
            queue<int> q;
            q.push(i);
            color[i] = 0;
            compId[i] = numComp;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        compId[v] = numComp;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return -1;
                    }
                }
            }
            numComp++;
        }

        vector<int> bestForComp(numComp, 0);
        for (int i = 1; i <= n; i++) {
            int depth = bfsDepth(i, adj, n);
            bestForComp[compId[i]] = max(bestForComp[compId[i]], depth);
        }

        int total = 0;
        for (int b : bestForComp) total += b;
        return total;
    }
};
