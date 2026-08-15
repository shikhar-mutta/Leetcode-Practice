// Link: https://leetcode.com/problems/campus-bikes-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<vector<int>> dist(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dist[i][j] = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);

        vector<int> dp(1 << m, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[mask] == INT_MAX) continue;
            int i = __builtin_popcount(mask);
            if (i >= n) continue;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) continue;
                int nmask = mask | (1 << j);
                dp[nmask] = min(dp[nmask], dp[mask] + dist[i][j]);
            }
        }
        int best = INT_MAX;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) == n) best = min(best, dp[mask]);
        }
        return best;
    }
};
