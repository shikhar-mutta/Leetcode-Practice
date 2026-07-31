// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(nk)
//  Approach: DP + Binary Search
//  We can use a DP array to store the maximum value we can get by attending events.
//  The first dimension is the index of the event we are currently attending, and the second dimension is the number of events we have attended so far. We can use binary search to find the last event that starts before the current event starts. We can use a helper function to find the last event that starts before the current event starts. We can use a helper function to find the maximum value we can get by attending events.
class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        vector<pair<int, int>> ends;
        for (int i = 0; i < n; i++)
        {
            ends.push_back({events[i][1], i});
        }
        sort(ends.begin(), ends.end());
        int maxv = 0;
        for (int i = 0; i < n; i++)
        {
            int start = events[ends[i].second][0];
            int finish = events[ends[i].second][1];
            int value = events[ends[i].second][2];
            int it =
                lower_bound(ends.begin(), ends.end(), make_pair(start, 0)) -
                ends.begin() - 1;

            // find last event that starts before start
            if (it < 0)
            {
                if (i == 0)
                {
                    dp[i][1] = value;
                    continue;
                }
                dp[i][1] = max(dp[i - 1][1], value);
                for (int j = 2; j <= k; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                continue;
            }
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[it][j - 1] + value);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                maxv = max(maxv, dp[i][j]);
            }
        }
        return maxv;
    }
};