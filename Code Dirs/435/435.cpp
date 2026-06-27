// Link: https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(1).
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int removals = 0, prevEnd = INT_MIN;
        for (auto &iv : intervals)
        {
            if (iv[0] >= prevEnd)
                prevEnd = iv[1];
            else
                removals++;
        }
        return removals;
    }
};
