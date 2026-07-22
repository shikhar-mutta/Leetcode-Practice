// Link: https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    //    Approach:
    //    1. We use a sliding window approach to find the number of contiguous subarrays whose product is less than k.
    //    2. We maintain a window defined by two pointers, left and right, and a variable to keep track of the product of the elements in the current window.
    //    3. We expand the window by moving the right pointer and multiplying the product by the new element. If the product becomes greater than or equal to k, we shrink the window from the left by moving the left pointer and dividing the product by the element that is no longer in the window.
    //    4. For each position of the right pointer, the number of valid subarrays ending at that position is given by the length of the current window (right - left + 1). We accumulate this count to get the total number of valid subarrays.
    //    5. The process continues until the right pointer has traversed the entire array, and we return the accumulated count as the final result.
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int left = 0;
        long long product = 1;
        int count = 0;
        for (int right = 0; right < (int)nums.size(); right++)
        {
            product *= nums[right];
            while (product >= k)
            {
                product /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
