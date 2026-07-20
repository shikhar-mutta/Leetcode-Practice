// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) in average case, O(n) in worst case
    // SC: O(1)
    // Approach:
    // 1. Use binary search to find the target in the rotated sorted array.
    // 2. If the middle element is equal to the target, return true.
    // 3. If the leftmost element is equal to the middle element and the middle element is equal to the rightmost element, we cannot determine which side is sorted, so we increment the left pointer and decrement the right pointer.
    // 4. If the leftmost element is less than or equal to the middle element, then the left side is sorted. If the target is within the range of the left side, we search in the left side; otherwise, we search in the right side.
    // 5. If the leftmost element is greater than the middle element, then the right side is sorted. If the target is within the range of the right side, we search in the right side; otherwise, we search in the left side.
    // 6. If we exit the loop without finding the target, return false.
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
            }
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
