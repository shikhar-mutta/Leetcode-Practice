// Link: https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Approach 2: Sort the intervals and then merge them in one pass.
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;

        // // Best Approach 1: Sort the intervals and then merge them in one pass.
        // int n = intervals.size();
        // vector<vector<int>> ans;
        // sort(intervals.begin(), intervals.end());
        // for (int i = 0; i < n;)
        // {
        //     int start = intervals[i][0], end = intervals[i][1], j = i + 1;
        //     while (j < n && intervals[j][0] <= end)
        //     {
        //         end = max(end, intervals[j][1]);
        //         j++;
        //     }
        //     ans.push_back({start, end});
        //     i = j;
        // }
        // return ans;
    }
};