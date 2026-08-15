// Link: https://leetcode.com/problems/earliest-time-to-finish-one-task/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int earliestTime(vector<vector<int>> &tasks)
    {
        int minTime = INT_MAX;
        for (const auto &task : tasks)
            minTime = min(minTime, task[0] + task[1]);

        return minTime;
    }
};
