// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //     1. We can use a single pass through the array to calculate the maximum and minimum prefix sums.
    //     2. We can keep track of the current prefix sum and update the maximum and minimum prefix sums as we iterate through the array.
    //     3. The maximum absolute sum of any subarray is the difference between the maximum and minimum prefix sums.
    //  Note: We can use long long to avoid integer overflow when calculating the prefix sums.
    int maxAbsoluteSum(vector<int> &nums)
    {
        long long sum = 0, mx = 0, mn = 0;
        for (int x : nums)
        {
            sum += x;
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        return mx - mn;
    }
};