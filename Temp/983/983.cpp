// Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());
        for (int d = 1; d <= lastDay; d++) {
            if (!travelDays.count(d)) { dp[d] = dp[d-1]; continue; }
            int c1 = dp[d-1] + costs[0];
            int c7 = dp[max(0, d-7)] + costs[1];
            int c30 = dp[max(0, d-30)] + costs[2];
            dp[d] = min({c1, c7, c30});
        }
        return dp[lastDay];
    }
};
