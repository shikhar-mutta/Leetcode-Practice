// Link: https://leetcode.com/problems/split-array-with-minimum-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: We can iterate through the array and keep track of the sum of the left and right parts. We can use two pointers to find the point where the left part is less than or equal to the right part. We can then calculate the absolute difference between the two parts and return the minimum difference found.
class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long left = 0, right = 0, i;
        for (i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                left += nums[i];
            else
                break;
        }
        int idx = i;
        bool flag = false;
        for (i = idx; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                right += nums[i + 1];
            else if (i == idx && nums[i] == nums[i + 1])
            {
                left += nums[i];
                right += nums[i + 1];
                flag = true;
            }
            else
                return -1;
        }
        if (flag)
            return abs(left - right);
        return min(abs((right + nums[idx]) - left),
                   abs(right - (left + nums[idx])));
    }
};