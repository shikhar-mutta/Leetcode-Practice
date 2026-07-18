// Link: https://leetcode.com/problems/find-if-array-can-be-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn). SC: O(1)
    //  Approach:
    //  1. Iterate through the array and group elements with the same number of set bits.
    //  2. For each group, find the minimum and maximum elements.
    //  3. Check if the minimum element of the current group is greater than or equal to the maximum element of the previous group.
    //  4. If any group violates this condition, return false. Otherwise, return true.
    //  5. Return true if the array can be sorted by the given condition, otherwise return false.
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int prevMax = INT_MIN;
        int i = 0;
        while (i < n)
        {
            int bits = __builtin_popcount(nums[i]);
            int curMin = nums[i], curMax = nums[i];
            int j = i + 1;
            while (j < n && __builtin_popcount(nums[j]) == bits)
            {
                curMin = min(curMin, nums[j]);
                curMax = max(curMax, nums[j]);
                j++;
            }
            if (curMin < prevMax)
                return false;
            prevMax = curMax;
            i = j;
        }
        return true;
    }
};
