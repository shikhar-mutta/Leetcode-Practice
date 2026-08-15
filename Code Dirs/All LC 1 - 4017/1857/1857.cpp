// Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);

        int visited = 0, best = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            count[u][colors[u] - 'a']++;
            best = max(best, count[u][colors[u] - 'a']);
            for (int v : adj[u]) {
                for (int c = 0; c < 26; c++) count[v][c] = max(count[v][c], count[u][c]);
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return visited == n ? best : -1;
    }
};
