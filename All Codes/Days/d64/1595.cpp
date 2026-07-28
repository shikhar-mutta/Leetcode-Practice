// Link: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        vector<int> minCol(m, INT_MAX);
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                minCol[j] = min(minCol[j], cost[i][j]);
        vector<vector<int>> dp(n + 1, vector<int>(1 << m, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << m); mask++) {
                if (dp[i][mask] == INT_MAX) continue;
                for (int j = 0; j < m; j++) {
                    int nmask = mask | (1 << j);
                    dp[i+1][nmask] = min(dp[i+1][nmask], dp[i][mask] + cost[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[n][mask] == INT_MAX) continue;
            int extra = 0;
            for (int j = 0; j < m; j++)
                if (!(mask & (1 << j))) extra += minCol[j];
            ans = min(ans, dp[n][mask] + extra);
        }
        return ans;
    }
};
