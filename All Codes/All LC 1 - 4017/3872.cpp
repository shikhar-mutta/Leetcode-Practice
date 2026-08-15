// Link: https://leetcode.com/problems/longest-arithmetic-sequence-after-changing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: use a sliding window to find the longest arithmetic sequence, and try changing at most one element to improve the result.
//  1. Use two pointers l and r to represent the current window of the arithmetic sequence.
//  2. Calculate the common difference diff of the current window.
//  3. If the next element nums[r] - nums[r-1] is equal to diff, then we can extend the window and update the max_len.
//  4. If the next element nums[r] - nums[r-1] is not equal to diff, then we can try changing at most one element to make the sequence arithmetic. We can scan forward with a temporary pointer tmp_r to find the longest sequence that can be formed by changing one element. We update the max_len accordingly and move the left pointer l to the previous position of r-1. We also update the common difference diff to the new difference nums[r] - nums[r-1].
//  5. We repeat steps 3-4 until we reach the end of the array.
//  6. We reverse the array and repeat the process to find the longest arithmetic sequence in the reversed array. We return the maximum of the two results as the final answer.
class Solution
{
    // Returns the longest arithmetic sequence, based on a slinding window
    int getLongestArithmetic(vector<int> &nums)
    {
        int max_len = 2, diff = nums[1] - nums[0], n = nums.size();
        for (int l = 0, r = 2; r < n; r++)
        {
            int cur_diff = nums[r] - nums[r - 1];
            if (cur_diff == diff)
            {
                max_len = max(max_len, r - l + 1);
                continue;
            }

            // Change at most one element by scanning forward with tmp_r
            int pre_r = r - 1, tmp_r = r;
            int cur = nums[r - 1] + diff;
            while (tmp_r + 1 < n && nums[tmp_r + 1] - cur == diff)
            {
                cur = nums[tmp_r + 1];
                tmp_r++;
            }

            max_len = max(max_len, tmp_r - l + 1);
            diff = cur_diff;
            l = pre_r;
        }

        return max_len;
    }

public:
    int longestArithmetic(vector<int> &nums)
    {
        int max_len = getLongestArithmetic(nums);
        reverse(nums.begin(), nums.end());
        return max(max_len, getLongestArithmetic(nums));
    }
};