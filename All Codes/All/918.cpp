// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. We can find the maximum subarray sum in a circular array by finding the maximum subarray sum in a non-circular array and the minimum subarray sum in a non-circular array.
    //  2. The maximum subarray sum in a circular array is the maximum of the maximum subarray sum in a non-circular array and the total sum of the array minus the minimum subarray sum in a non-circular array.
    //  3. If the maximum subarray sum in a non-circular array is negative, then the maximum subarray sum in a circular array is also negative, and we return the maximum subarray sum in a non-circular array.
    //  4. Otherwise, we return the maximum of the maximum subarray sum in a non-circular array and the total sum of the array minus the minimum subarray sum in a non-circular array.
    //  5. We can find the maximum subarray sum in a non-circular array using Kadane's algorithm, and we can find the minimum subarray sum in a non-circular array using a similar approach.
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = 0;
        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int x : nums)
        {
            curMax = max(curMax + x, x);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + x, x);
            minSum = min(minSum, curMin);
            total += x;
        }

        if (maxSum < 0)
            return maxSum;
        return max(maxSum, total - minSum);
    }
};
