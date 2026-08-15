// Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) - The function iterates through the array once, with the left pointer moving at most n times, resulting in a linear time complexity.
    // SC: O(1) - The function uses a constant amount of extra space, regardless of the input size, as it only maintains a few integer variables for tracking the sum and indices.
    //  Approach:
    //  1. We initialize two pointers, left and right, to represent the current window of elements being considered. We also maintain a variable sum to keep track of the sum of the elements within the window and a variable best to store the length of the smallest valid subarray found.
    //  2. We iterate through the array using the right pointer, adding each element to the sum. Whenever the sum becomes greater than or equal to the target, we check if the current window size (right - left + 1) is smaller than the best found so far. If it is, we update best. We then move the left pointer to the right, subtracting the element at left from sum, and continue this process until the sum is less than the target again.

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, sum = 0, best = INT_MAX;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                best = min(best, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
