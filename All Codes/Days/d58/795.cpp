// Link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of elements in the input array nums.
    // SC: O(1), as we are using a constant amount of space.
    // Approach:
    // 1. We define a helper function countLE that counts the number of subarrays with maximum element less than or equal to a given bound.
    // 2. We iterate through the input array nums and maintain a count of the current subarray length that satisfies the condition.
    // 3. If the current element is less than or equal to the bound, we increment the current subarray length. Otherwise, we reset the current subarray length to 0.
    // 4. We add the current subarray length to the total count of subarrays.
    // 5. Finally, we return the difference between the counts of subarrays with maximum element less than or equal to right and the counts of subarrays with maximum element less than or equal to left - 1, which gives us the number of subarrays with maximum element in the range [left, right].
    long long countLE(vector<int> &nums, int bound)
    {
        long long count = 0, cur = 0;
        for (int x : nums)
        {
            if (x <= bound)
                cur++;
            else
                cur = 0;
            count += cur;
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        return countLE(nums, right) - countLE(nums, left - 1);
    }
};
