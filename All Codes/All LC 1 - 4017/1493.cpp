// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //    Approach:
    //    1. Use a sliding window approach to find the longest subarray of 1s after deleting one element.
    //    2. Initialize two pointers, left and right, to represent the current window of the subarray. Also, initialize a variable zeros to count the number of zeros in the current window and a variable res to store the maximum length of the subarray found so far.
    //    3. Iterate through the array using the right pointer.
    //    4. If the current element is 0, increment the zeros count.
    //    5. If the zeros count exceeds 1, move the left pointer to the right until the zeros count is less than or equal to 1, decrementing the zeros count if the element at the left pointer is 0.
    //    6. Update the maximum length of the subarray found so far by calculating the length of the current window (right - left) and comparing it with the previous maximum length.
    //    7. Return the maximum length of the subarray found after iterating through the entire array.
    int longestSubarray(vector<int> &nums)
    {
        int left = 0, zeros = 0, res = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] == 0)
                ++zeros;
            while (zeros > 1)
            {
                if (nums[left] == 0)
                    --zeros;
                ++left;
            }
            res = max(res, right - left);
        }
        return res;
    }
};