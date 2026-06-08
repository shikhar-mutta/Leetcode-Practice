// Link: https://leetcode.com/problems/sum-of-variable-length-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    int subarraySum(vector<int> &nums)
    {
        int totalSum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int st = max(0, i - nums[i]), end = i;
            for (int j = st; j <= end; j++)
                totalSum += nums[j];
        }
        return totalSum;
    }
};
