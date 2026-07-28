// Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*26 + e)  SC: O(n*26)
// Approach: Kahn's topological sort; dp[node][c] = max count of color c along
// any path ending at node. Process nodes in topo order, propagate dp to
// successors. If not all nodes get processed (cycle), return -1.
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
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        int processed = 0, ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;
            dp[u][colors[u] - 'a']++;
            ans = max(ans, dp[u][colors[u] - 'a']);
            for (int v : adj[u]) {
                for (int c = 0; c < 26; c++) dp[v][c] = max(dp[v][c], dp[u][c]);
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return processed == n ? ans : -1;
    }
};
