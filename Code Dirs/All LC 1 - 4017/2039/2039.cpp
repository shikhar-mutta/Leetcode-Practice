// Link: https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int roundTrip = 2 * dist[i];
            int lastSent = ((roundTrip - 1) / patience[i]) * patience[i];
            int idleAt = lastSent + roundTrip + 1;
            ans = max(ans, idleAt);
        }
        return ans;
    }
};
