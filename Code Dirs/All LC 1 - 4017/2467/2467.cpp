// Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<int> bobTime(n, INT_MAX);
        int cur = bob, t = 0;
        while (cur != -1) {
            bobTime[cur] = t++;
            cur = parent[cur];
        }

        int best = INT_MIN;
        function<void(int,int,int,long long)> dfs = [&](int u, int p, int aliceTime, long long gain) {
            if (aliceTime < bobTime[u]) gain += amount[u];
            else if (aliceTime == bobTime[u]) gain += amount[u] / 2;

            bool isLeaf = true;
            for (int v : adj[u]) {
                if (v != p) {
                    isLeaf = false;
                    dfs(v, u, aliceTime + 1, gain);
                }
            }
            if (isLeaf) best = max(best, (int)gain);
        };
        dfs(0, -1, 0, 0);
        return best;
    }
};
