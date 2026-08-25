// Link: https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int count = 0; // intervals kept
        int prevEnd = intervals[0][1];
        count = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= prevEnd)
            {
                // no overlap, keep this interval
                count++;
                prevEnd = intervals[i][1];
            }
            // else: overlaps, remove it (i.e., skip — don't update prevEnd)
        }
        return intervals.size() - count;
    }
};
