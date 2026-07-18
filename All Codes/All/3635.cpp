// Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m)
// SC: O(1)
//  Approach:
//  1. We can find the earliest finish time for land and water rides by first finding the minimum finish time for land and water rides separately.
//  2. We can then iterate through the land and water rides and for each ride, we can calculate the finish time by taking the maximum of the minimum finish time of the other type of ride and the start time of the current ride, and adding the duration of the current ride to it. We can keep track of the minimum finish time among all the rides and return it as the answer.
// 3. Finally, we can return the minimum finish time among all the rides as the answer.
class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int ans = INT_MAX;
        int minlandfinish = INT_MAX;
        int minwaterfinish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
        {

            minlandfinish = min(minlandfinish, landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < waterStartTime.size(); j++)
        {
            minwaterfinish = min(minwaterfinish, waterStartTime[j] + waterDuration[j]);
        }
        for (int i = 0; i < landStartTime.size(); i++)
        {
            ans = min(ans, max(minwaterfinish, landStartTime[i]) + landDuration[i]);
        }
        for (int j = 0; j < waterStartTime.size(); j++)
        {
            ans = min(ans, max(minlandfinish, waterStartTime[j]) + waterDuration[j]);
        }

        return ans;
    }
};