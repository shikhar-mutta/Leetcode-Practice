// Link: https://leetcode.com/problems/find-right-interval/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    // Approach: We first create a vector of pairs to store the start values of the intervals along with their original indices. We then sort this vector based on the start values. For each interval, we use binary search (lower_bound) to find the smallest start value that is greater than or equal to the end value of the current interval. If such a start value exists, we store its original index in the result vector; otherwise, we store -1.
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<pair<int, int>> starts(n); // (start value, original index)
        for (int i = 0; i < n; i++)
            starts[i] = {intervals[i][0], i};
        sort(starts.begin(), starts.end());

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            // smallest start >= this interval's end
            auto it = lower_bound(starts.begin(), starts.end(),
                                  make_pair(intervals[i][1], INT_MIN));
            res[i] = (it == starts.end()) ? -1 : it->second;
        }
        return res;
    }
};
