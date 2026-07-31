// Link: https://leetcode.com/problems/longest-non-decreasing-subarray-after-replacing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: sliding window technique to find the longest non-decreasing subarray after replacing at most one element.
//  We keep track of the current subarray length and the previous subarray length, and update the result accordingly.
//  We also check the conditions for replacing an element to ensure that the subarray remains non-decreasing.
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int res = 1, j = 0, prev_len = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (i == nums.size() || nums[i - 1] > nums[i])
            {
                int len = i - j;
                res = max(res, len + 1);
                if (j > 1 && nums[j - 2] <= nums[j])
                    res = max(res, len + prev_len);
                if (j && j + 1 < i && nums[j - 1] <= nums[j + 1])
                    res = max(res, len + prev_len);
                j = i;
                prev_len = len;
            }
        }
        return min(res, (int)nums.size());
    }
};