// Link: https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Approach1: kadane's algorithm
        int mx = INT_MIN, sum = 0, n = nums.size(), i = 0;
        while (i < n)
        {

            sum += nums[i++];
            if (sum > mx)
                mx = sum;
            if (sum < 0)
                sum = 0;
        }
        return mx;
    }
};