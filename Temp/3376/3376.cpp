// Link: https://leetcode.com/problems/minimum-time-to-break-locks-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int full = 1 << n;
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            int cnt = __builtin_popcount(mask);
            int x = 1 + k * cnt;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                int timeNeeded = (strength[i] + x - 1) / x;
                int nmask = mask | (1 << i);
                dp[nmask] = min(dp[nmask], dp[mask] + timeNeeded);
            }
        }
        return dp[full - 1];
    }
};
