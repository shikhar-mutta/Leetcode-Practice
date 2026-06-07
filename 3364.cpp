// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        int sum = 0, ans = -1;
        for (int i = l; i <= r; i++)
        {
            sum = 0;
            // init pipeline
            for (int j = 0; j < i; j++)
            {
                sum += nums[j];
            }
            if (sum > 0)
                ans = min(ans, sum);
            // sliding window
            for (int j = i; j < n; j++)
            {
                sum += nums[j] - nums[j - i];
                if (sum > 0)
                    ans = min(ans, sum);
            }
        }
        return ans;
    }
};
