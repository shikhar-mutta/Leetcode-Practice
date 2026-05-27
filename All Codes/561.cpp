// Link: https://leetcode.com/problems/array-partition-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2)
        {
            // Add the minimum of the current pair (nums[i], nums[i + 1]) to the sum
            sum += min(nums[i], nums[i + 1]);
        }
        return sum;
    }
};