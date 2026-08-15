// Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach 1: sort + BS. TC: O(nlogn), SC: O(1).
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;

        while (left < right) // BS
            if (nums[left] + nums[right] == 0)
                return nums[right];
            else if (nums[left] + nums[right] < 0)
                left++;
            else
                right--;

        return -1;
    }
};
