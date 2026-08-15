// Link: https://leetcode.com/problems/the-most-similar-path-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        int m = targetPath.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(m, vector<int>(n, -1));

        for (int v = 0; v < n; v++) {
            dp[0][v] = (names[v] != targetPath[0]) ? 1 : 0;
        }

        for (int i = 1; i < m; i++) {
            for (int v = 0; v < n; v++) {
                int cost = (names[v] != targetPath[i]) ? 1 : 0;
                for (int u : adj[v]) {
                    if (dp[i-1][u] + cost < dp[i][v]) {
                        dp[i][v] = dp[i-1][u] + cost;
                        parent[i][v] = u;
                    }
                }
            }
        }

        int bestEnd = 0;
        for (int v = 1; v < n; v++) if (dp[m-1][v] < dp[m-1][bestEnd]) bestEnd = v;

        vector<int> path(m);
        int cur = bestEnd;
        for (int i = m - 1; i >= 0; i--) {
            path[i] = cur;
            cur = parent[i][cur];
        }
        return path;
    }
};
