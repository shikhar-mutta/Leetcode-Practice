// Link: https://leetcode.com/problems/paint-house-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;
        // dp[color][groups] = min cost up to current house
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));
        vector<vector<int>> ndp;
        for (int c = 1; c <= n; c++) {
            if (houses[0] == 0) dp[c][1] = cost[0][c - 1];
            else if (houses[0] == c) dp[c][1] = 0;
        }
        for (int i = 1; i < m; i++) {
            ndp.assign(n + 1, vector<int>(target + 1, INF));
            for (int c = 1; c <= n; c++) {
                int payCost = (houses[i] == 0) ? cost[i][c - 1] : (houses[i] == c ? 0 : -1);
                if (payCost < 0) continue;
                for (int pc = 1; pc <= n; pc++) {
                    for (int g = 1; g <= target; g++) {
                        if (dp[pc][g] == INF) continue;
                        int ng = g + (pc != c ? 1 : 0);
                        if (ng > target) continue;
                        ndp[c][ng] = min(ndp[c][ng], dp[pc][g] + payCost);
                    }
                }
            }
            dp = ndp;
        }
        int ans = INF;
        for (int c = 1; c <= n; c++) ans = min(ans, dp[c][target]);
        return ans == INF ? -1 : ans;
    }
};
