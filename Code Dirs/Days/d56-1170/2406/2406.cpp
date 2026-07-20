// Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of intervals and m is the range of the intervals (in this case, 1e6)
    // SC: O(m) where m is the range of the intervals (in this case, 1e6)
    //  Approach:
    //  1. Create an array of size 1e6 + 1 to store the number of intervals that start and end at each point.
    //  2. Iterate through the intervals and for each interval, increment the start point and decrement the end point + 1 in the array.
    //  3. Iterate through the array and keep a running sum of the number of intervals that are currently active. The maximum value of this running sum will be the minimum number of groups needed to divide the intervals.
    //  4. Return the maximum value of the running sum.
    int minGroups(vector<vector<int>> &intervals)
    {

        int line[1000005] = {};
        int maxEle = -1;

        for (auto &e : intervals)
        {
            int start = e[0], end = e[1];
            line[start] += 1;
            line[end + 1] -= 1;
        }

        for (int i = 1; i < 1000001; i++)
        {
            line[i] += line[i - 1];
            maxEle = max(maxEle, line[i]);
        }

        return maxEle;
    }
};
