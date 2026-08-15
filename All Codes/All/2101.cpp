// Link: https://leetcode.com/problems/detonate-the-maximum-bombs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) adj[i].push_back(j);
            }
        }
        int best = 0;
        for (int s = 0; s < n; s++) {
            vector<bool> visited(n, false);
            visited[s] = true;
            queue<int> q; q.push(s);
            int count = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) { visited[v] = true; count++; q.push(v); }
                }
            }
            best = max(best, count);
        }
        return best;
    }
};
