// Link: https://leetcode.com/problems/climbing-stairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int d = 1; d <= 3; d++) {
                int i = j - d;
                if (i < 0) continue;
                if (dp[i] == LLONG_MAX) continue;
                long long cand = dp[i] + costs[j - 1] + (long long)d * d;
                dp[j] = min(dp[j], cand);
            }
        }
        return (int)dp[n];
    }
};
