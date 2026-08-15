// Link: https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: We can use a two pointer approach to solve this problem. We can use two pointers to keep track of the current subarray and the previous subarray. We can then check if the current subarray can be merged with the previous subarray by checking if the last element of the previous subarray is less than the first element of the current subarray. If it is, we can merge the two subarrays and update the result. If it is not, we can update the result with the length of the current subarray and move the left pointer to the right pointer. We can also check if the current subarray can be merged with the previous subarray by checking if the last element of the previous subarray is greater than the first element of the current subarray. If it is, we can merge the two subarrays and update the result. If it is not, we can update the result with the length of the current subarray and move the left pointer to the right pointer. We can continue this process until we reach the end of the array. The final result will be the maximum length of the alternating subarray that can be obtained by removing at most one element.
class Solution
{
public:
    int longestAlternating(vector<int> &nums)
    {
        int N = size(nums), pl = -2, pr = -2, l = 0, res = 1;
        while (1)
        {
            while (l < N - 1 && nums[l + 1] == nums[l])
                ++l;
            if (l + 1 == N)
                break;
            int r = l + 1, d = nums[l + 1] - nums[l], d2;
            while (r < N - 1 && nums[r + 1] != nums[r] &&
                   ((d2 = nums[r + 1] - nums[r]) ^ d) < 0)
            {
                ++r;
                d = d2;
            }
            res = max(res,
                      l == pr || l == pr + 1 && ((nums[pr - 1] - nums[pr]) ^
                                                 (nums[l + 1] - nums[l])) >= 0
                          ? r - pl
                          : r - l + 1);
            pl = l;
            pr = r;
            l = pr;
        }
        return res;
    }
};
