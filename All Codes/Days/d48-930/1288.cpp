// Link: https://leetcode.com/problems/remove-covered-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + n) = O(nlogn), SC: O(1)
    //  Approach:
    //  1. Sort the intervals by their starting point in ascending order. If two intervals have the same starting point, sort them by their ending point in descending order. This ensures that if one interval can cover another, it will come first in the sorted order.
    //  2. Initialize a variable to keep track of the maximum right endpoint seen so far. Iterate through the sorted intervals and for each interval, check if its right endpoint is greater than the maximum right endpoint seen so far. If it is, it means this interval is not covered by any previous interval, so we increment the count and update the maximum right endpoint. If the right endpoint is less than or equal to the maximum right endpoint, it means this interval is covered by a previous interval, and we do not increment the count.
    //  3. Return the count of intervals that are not covered by any other interval.
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        // sort by left asc, then right desc: a potential coverer comes first
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

        int count = 0, maxRight = 0;
        for (auto &iv : intervals)
        {
            if (iv[1] > maxRight) // not covered by anything before it
            {
                count++;
                maxRight = iv[1];
            }
        }
        return count;
    }
};
