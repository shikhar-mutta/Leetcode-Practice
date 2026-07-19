// Link: https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) on average — nth_element (introselect) is linear on average and dominates; each loop is O(n).
// SC: O(1) extra space, the partition is done in place.
// Approach:
// 1. Find the median of the array using nth_element.
// 2. If the median is less than k, increment elements from the median to the end of the array to make them at least k.
// 3. If the median is greater than k, decrement elements from the start of the array to the median to make them at most k.
// 4. Return the total number of operations performed.
class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        const int n = nums.size(), mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        long long res = 0;
        if (nums[mid] < k)
        {
            for (int i = mid; i < n; ++i)
                res += max(0, k - nums[i]);
        }
        else
        {
            for (int i = 0; i <= mid; ++i)
                res += max(0, nums[i] - k);
        }
        return res;
    }
};
