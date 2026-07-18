// Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size(), sum = nums[0], mx = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                sum += nums[i];
            }
            else
            {
                if (sum > mx) // Update the maximum sum if the current sum is greater
                    mx = sum;
                sum = nums[i];
            }
        }
        if (sum > mx)
            mx = sum;

        return mx;
    }
};
