// Link: https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort by end time, greedily keep an interval if it starts at or
// after the last kept interval's end; count removals as the rest
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        long long end = LLONG_MIN;
        for (auto& iv : intervals) {
            if (iv[0] >= end) end = iv[1];
            else count++;
        }
        return count;
    }
};
