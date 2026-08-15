// Link: https://leetcode.com/problems/find-right-interval/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort (start, originalIndex) pairs, for each interval's end,
// binary search the smallest start >= end
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts(n);
        for (int i = 0; i < n; i++) starts[i] = {intervals[i][0], i};
        sort(starts.begin(), starts.end());

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(end, INT_MIN));
            res[i] = (it == starts.end()) ? -1 : it->second;
        }
        return res;
    }
};
