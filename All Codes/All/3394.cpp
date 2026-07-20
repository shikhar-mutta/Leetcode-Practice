// Link: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. For each rectangle, we can represent it as an interval on the x-axis and an interval on the y-axis.
    //  2. We can sort the intervals on the x-axis and the y-axis separately.
    //  3. We can then iterate through the sorted intervals and count the number of groups of overlapping intervals. If we have at least 3 groups of overlapping intervals on either axis, then we can cut the grid into sections.
    //  4. If we have less than 3 groups of overlapping intervals on both axes, then we cannot cut the grid into sections.
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        auto hasThreeGroups = [&](int axis) -> bool
        {
            vector<pair<int, int>> intervals;
            for (auto &rect : rectangles)
            {
                intervals.push_back({rect[axis], rect[axis + 2]});
            }

            sort(intervals.begin(), intervals.end());

            int groups = 0;
            int far = -1;

            for (auto &[start, end] : intervals)
            {
                if (start >= far)
                {
                    groups++;
                    far = end;
                }
                else
                {
                    far = max(far, end);
                }
            }

            return groups >= 3;
        };

        return hasThreeGroups(0) || hasThreeGroups(1);
    }
};
