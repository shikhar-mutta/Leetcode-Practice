// Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    // Approach:
    //   1. Calculate the target sum by multiplying k with threshold.
    //   2. Use a sliding window approach to calculate the sum of subarrays of size k.
    //   3. If the sum of the current subarray is greater than or equal to the target sum, increment the result counter.
    //   4. Return the result counter.
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        long long target = (long long)k * threshold;
        long long sum = 0;
        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (i >= k)
                sum -= arr[i - k];
            if (i >= k - 1 && sum >= target)
                ++res;
        }
        return res;
    }
};