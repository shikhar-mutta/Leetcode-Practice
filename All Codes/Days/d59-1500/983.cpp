// Link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of days in the year (365).
    // SC: O(n) where n is the number of days in the year (365).
    // Approach:
    //  1. We will use dynamic programming to solve this problem.
    //  2. We will create a dp array of size lastDay + 1 where lastDay is the last day of travel.
    //  3. We will iterate through each day from 1 to lastDay and calculate the minimum cost for that day.
    //  4. If the day is not a travel day, we will set dp[d] = dp[d - 1].
    //  5. If the day is a travel day, we will calculate the cost for that day by considering the three options: 1-day pass, 7-day pass, and 30-day pass.
    //  6. We will return dp[lastDay] as the minimum cost for all travel days.
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int d = 1; d <= lastDay; d++)
        {
            if (!travelDays.count(d))
            {
                dp[d] = dp[d - 1];
                continue;
            }
            int cost1 = dp[d - 1] + costs[0];
            int cost7 = dp[max(0, d - 7)] + costs[1];
            int cost30 = dp[max(0, d - 30)] + costs[2];
            dp[d] = min({cost1, cost7, cost30});
        }
        return dp[lastDay];
    }
};
