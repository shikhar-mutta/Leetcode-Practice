// Link: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n)
    // SC: O(1)
    //  Approach:
    //  1. Sort the nums array in ascending order.
    //  2. Initialize two pointers, left and right, to the start and middle of the array, respectively. The left pointer will point to the smaller elements, and the right pointer will point to the larger elements.
    //  3. Initialize a count variable to keep track of the number of marked indices.
    //  4. Iterate through the array using the right pointer:
    //     a. If the element at the left pointer is less than or equal to half of the element at the right pointer, it means we can mark both indices. In this case, we increment the count by 2 and move both pointers forward.
    //     b. If the element at the left pointer is greater than half of the element at the right pointer, it means we cannot mark both indices. In this case, we only move the right pointer forward to find a larger element that can be paired with the current left element.
    //  5. Return the final count of marked indices.
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] * 2 > nums[n - 1])
            return 0;
        int left = 0, right = (n + 1) / 2, count = 0;
        while (right < n)
        {
            if (nums[left] * 2 <= nums[right])
            {
                count += 2;
                left++, right++;
            }
            else
            {
                right++;
            }
        }
        return count;
    }
};