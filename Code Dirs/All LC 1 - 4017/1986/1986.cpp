// Link: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> sum(1 << n, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int low = mask & (-mask);
            int idx = __builtin_ctz(low);
            sum[mask] = sum[mask ^ low] + tasks[idx];
        }

        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if (sum[sub] <= sessionTime && dp[mask ^ sub] != INT_MAX) {
                    dp[mask] = min(dp[mask], dp[mask ^ sub] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
