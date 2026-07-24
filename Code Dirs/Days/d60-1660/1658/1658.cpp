// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array.
    // SC: O(1) for storing the result.
    // Approach:
    //       1. Calculate the total sum of the array.
    //       2. Calculate the target sum by subtracting x from the total sum.
    //       3. Use a sliding window approach to find the longest subarray with a sum equal to the target sum.
    //       4. If such a subarray is found, return the length of the array minus the length of the subarray. Otherwise, return -1
    //       5. Return the result.
    int minOperations(vector<int> &nums, int x)
    {
        int total = 0, target = 0;
        for (int i : nums)
            total += i;
        target = total - x;
        if (target < 0)
            return -1;
        if (target == 0)
            return nums.size();
        int left = 0, max_length = -1, window_sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            window_sum += nums[right];
            while (window_sum > target && left < right)
            {
                window_sum -= nums[left];
                left++;
            }
            if (window_sum == target)
            {
                int length = right - left + 1;
                max_length = max(length, max_length);
            }
        }
        if (max_length == -1)
            return -1;
        return (nums.size() - max_length);
    }
};
