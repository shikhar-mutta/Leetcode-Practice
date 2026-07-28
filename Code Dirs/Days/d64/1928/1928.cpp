// Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(maxTime * E)  SC: O(maxTime * n)
// Approach: dp[t][u] = min fee cost to reach node u using exactly t total
// time. Relax all edges for each time step (bounded knapsack-like DP over
// time), then answer is min over dp[t][n-1] for all t<=maxTime.
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n); // (neighbor, time)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX));
        dp[0][0] = passingFees[0];
        for (int t = 0; t < maxTime; t++) {
            for (int u = 0; u < n; u++) {
                if (dp[t][u] == INT_MAX) continue;
                for (auto& [v, w] : adj[u]) {
                    if (t + w <= maxTime) {
                        int cost = dp[t][u] + passingFees[v];
                        if (cost < dp[t+w][v]) dp[t+w][v] = cost;
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int t = 0; t <= maxTime; t++) ans = min(ans, dp[t][n-1]);
        return ans == INT_MAX ? -1 : ans;
    }
};
