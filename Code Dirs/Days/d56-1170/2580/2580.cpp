// Link: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n)
    // SC: O(1)
    //  Approach:
    //  1. Sort the ranges based on their starting point.
    //  2. Initialize a variable maxEnd to keep track of the maximum end point of the current group of overlapping ranges.
    //  3. Iterate through the sorted ranges:
    //     a. If the starting point of the current range is greater than maxEnd, it means that the current range does not overlap with the previous group of ranges. In this case, we can form a new group of ranges, and we multiply the answer by 2 (since we can either include or exclude the current range in the new group). We also update maxEnd to be the end point of the current range.
    //     b. If the starting point of the current range is less than or equal to maxEnd, it means that the current range overlaps with the previous group of ranges. In this case, we update maxEnd to be the maximum of maxEnd and the end point of the current range.
    //  4. Return the final answer modulo 1e9 + 7.
    int countWays(vector<vector<int>> &ranges)
    {
        const int MOD = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        long long ans = 1;
        int maxEnd = -1;
        for (auto &r : ranges)
        {
            if (r[0] > maxEnd)
            {
                ans = (ans * 2) % MOD;
                maxEnd = r[1];
            }
            else
                maxEnd = max(maxEnd, r[1]);
        }
        return (int)ans;
    }
};
