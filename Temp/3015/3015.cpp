// Link: https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--; y--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> ans(n, 0);
        for (int s = 0; s < n; s++) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(s); dist[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
                }
            }
            for (int t = 0; t < n; t++) {
                if (t != s) ans[dist[t] - 1]++;
            }
        }
        return ans;
    }
};
