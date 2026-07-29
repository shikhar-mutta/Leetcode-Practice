// Link: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: We use dynamic programming to find the minimum number of skips required to arrive at the meeting on time. We maintain a dp array where dp[j] represents the minimum time taken to reach the j-th segment with j skips. For each segment, we calculate the time taken without skipping and the time taken with skipping, updating the dp array accordingly. Finally, we check for the minimum number of skips required to reach the meeting on time by comparing the values in the dp array with the maximum time limit (hoursBefore * speed). If we find a valid number of skips, we return it; otherwise, we return -1 indicating that it's not possible to arrive on time even with all skips.
class Solution
{
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size();
        long long maxTimeLimit = (long long)hoursBefore * speed;
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for (int i = 0; i < n; ++i)
        {
            long long d = dist[i];

            for (int j = i; j >= 0; --j)
            {
                long long timeWithoutSkip =
                    ((dp[j] + speed - 1) / speed) * speed;
                long long nextTimeNoSkip = timeWithoutSkip + d;
                long long nextTimeWithSkip = 1e18;
                if (j > 0)
                {
                    nextTimeWithSkip = dp[j - 1] + d;
                }
                dp[j] = min(nextTimeNoSkip, nextTimeWithSkip);
            }
        }

        for (int j = 0; j <= n; ++j)
        {
            if (dp[j] <= maxTimeLimit)
            {
                return j;
            }
        }

        return -1;
    }
};