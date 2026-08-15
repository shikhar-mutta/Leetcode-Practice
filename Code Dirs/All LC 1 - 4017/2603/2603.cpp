// Link: https://leetcode.com/problems/collect-coins-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        vector<bool> removed(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1 && coins[i] == 0) q.push(i);

        int remaining = n;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (removed[u]) continue;
            removed[u] = true;
            remaining--;
            for (int v : adj[u]) {
                if (removed[v]) continue;
                degree[v]--;
                if (degree[v] == 1 && coins[v] == 0) q.push(v);
            }
        }

        for (int round = 0; round < 2; round++) {
            vector<int> leaves;
            for (int i = 0; i < n; i++)
                if (!removed[i] && degree[i] == 1) leaves.push_back(i);
            for (int u : leaves) {
                if (removed[u]) continue;
                removed[u] = true;
                remaining--;
                for (int v : adj[u]) {
                    if (!removed[v]) degree[v]--;
                }
            }
        }

        int remainingEdges = max(0, remaining - 1);
        if (remaining <= 0) remainingEdges = 0;
        return remainingEdges * 2;
    }
};
