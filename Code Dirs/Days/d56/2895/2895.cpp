// Link: https://leetcode.com/problems/minimum-processing-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogm), SC: O(1)
    //  Approach:
    //  1. Sort the processorTime and tasks in ascending order
    //  2. Assign the largest tasks to the fastest processors
    //  3. Return the maximum processing time among all processors
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        int m = processorTime.size();
        int n = tasks.size();
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int j = 0;
        int maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            while (count < 4 && j < n)
            {
                ans = max(ans, processorTime[i] + tasks[j]);
                count++;
                j++;
            }
        }
        return ans;
    }
};