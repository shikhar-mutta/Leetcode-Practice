// Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n < 1)
            return 0;
        // dp[i] = min cost to reach step i
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        // dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // The final step can be reached from either the last step or the second last step
        return min(dp[n - 1], dp[n - 2]);
    }
};
