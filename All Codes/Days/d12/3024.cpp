// Link: https://leetcode.com/problems/type-of-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1). SC: O(1).
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2])
            return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
            return "isosceles";
        return "scalene";
    }
};
