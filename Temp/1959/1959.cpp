// Link: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> cost(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            long long sum = 0, mx = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                mx = max(mx, (long long)nums[j]);
                cost[i][j] = mx * (j - i + 1) - sum;
            }
        }

        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(k + 1, vector<long long>(n, INF));
        for (int i = 0; i < n; i++) dp[0][i] = cost[0][i];

        for (int r = 1; r <= k; r++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[r-1][j] == INF) continue;
                    dp[r][i] = min(dp[r][i], dp[r-1][j] + cost[j+1][i]);
                }
            }
        }

        long long best = INF;
        for (int r = 0; r <= k; r++) best = min(best, dp[r][n-1]);
        return (int)best;
    }
};
