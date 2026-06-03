// Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int minDiff = nums[k - 1] - nums[0], n = nums.size();
        for (int i = k; i < n; i++)
            if (nums[i] - nums[i - k + 1] < minDiff)
                minDiff = nums[i] - nums[i - k + 1];

        return minDiff;
    }
};
