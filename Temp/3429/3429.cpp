// Link: https://leetcode.com/problems/paint-house-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        long long dp[6];
        memset(dp, 0, sizeof(dp));
        long long l = 0, r = n - 1;
        long long ans = 1e18;
        while (l < r) {
            long long ndp[6];
            memset(ndp, 0, sizeof(ndp));
            ndp[0] = cost[l][0] + cost[r][1] + min(dp[1], min(dp[3], dp[5]));
            ndp[1] = cost[l][1] + cost[r][2] + min(dp[0], min(dp[4], dp[5]));
            ndp[2] = cost[l][0] + cost[r][2] + min(dp[3], min(dp[4], dp[5]));
            ndp[3] = cost[l][1] + cost[r][0] + min(dp[0], min(dp[2], dp[4]));
            ndp[4] = cost[l][2] + cost[r][1] + min(dp[1], min(dp[2], dp[3]));
            ndp[5] = cost[l][2] + cost[r][0] + min(dp[0], min(dp[1], dp[2]));
            for (long long i = 0; i < 6; i++) dp[i] = ndp[i];
            l++;
            r--;
        }
        for (long long i = 0; i < 6; i++) ans = min(dp[i], ans);
        return ans;
    }
};
