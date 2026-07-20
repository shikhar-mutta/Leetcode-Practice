// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) on average, O(n) in the worst case when all elements are the same
    // SC: O(1)
    //  Approach:
    //  1. Use binary search to find the minimum element in the rotated sorted array.
    //  2. Initialize two pointers, l and r, to the start and end of the array.
    //  3. While l < r, calculate the mid index.
    //  4. If nums[mid] > nums[r], the minimum is in the right half, so set l = mid + 1.
    //  5. If nums[mid] < nums[r], the minimum is in the left half, so set r = mid.
    //  6. If nums[mid] == nums[r], we cannot determine the side, so decrement r by 1 to reduce the search space.
    //  7. When l == r, return nums[l] as the minimum element.
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                r--;
        }
        return nums[l];
    }
};
