// Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxAdjacentDistance(vector<int> &nums)
    {
        int n = nums.size(), maxDiff = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; i++)
        {
            int diff = abs(nums[i] - nums[i + 1]);
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};
