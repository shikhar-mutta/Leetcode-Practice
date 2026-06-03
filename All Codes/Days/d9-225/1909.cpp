// Link: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check if the array is strictly increasing after skipping the element at index skip
    bool isIncreasing(vector<int> &nums, int skip)
    {
        int prev = -1;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (i == skip)
                continue; // skip the element at index skip
            if (prev != -1 && nums[prev] >= nums[i])
                return false; // not strictly increasing
            prev = i;         // update prev to the current index
        }
        return true; // strictly increasing
    }

    bool canBeIncreasing(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            if (nums[i] >= nums[i + 1]) // inversion point
                return isIncreasing(nums, i) || isIncreasing(nums, i + 1);
        return true;
    }
};
