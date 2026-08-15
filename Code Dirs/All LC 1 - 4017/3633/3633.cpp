// Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(1)
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int n = landStartTime.size(), m = waterStartTime.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int landEnd = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++)
            {
                int waterEnd = waterStartTime[j] + waterDuration[j];
                ans = min(ans, max(landEnd, waterStartTime[j]) + waterDuration[j]); // land first
                ans = min(ans, max(waterEnd, landStartTime[i]) + landDuration[i]);  // water first
            }
        }
        return ans;
    }
};
