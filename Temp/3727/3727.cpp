// Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(n) + O(n/2) = O(n)
    // SC: O(1)
    // Approach:
    // 1. Square all the elements in the array.
    // 2. Find the median of the squared elements using nth_element.
    // 3. Subtract the sum of the first half of the squared elements from the sum of the second half of the squared elements to get the maximum alternating sum.
    // 4. Return the maximum alternating sum.
    long long maxAlternatingSum(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        int mid = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        long long result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < mid)
            {
                result -= nums[i];
            }
            else
            {
                result += nums[i];
            }
        }
        return result;
    }
};
