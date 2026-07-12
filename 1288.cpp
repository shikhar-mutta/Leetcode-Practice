// Link: https://leetcode.com/problems/remove-covered-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
