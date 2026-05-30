// Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end()); // Sort the array to bring negative numbers to the fronts
        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {                       // If the current number is negative
                nums[i] = -nums[i]; // Negate it to make it positive
                k--;                // Decrease the number of negations left
            }
            else
            {
                break; // No more negative numbers to negate, break out of the loop
            }
        }
        if (k > 0)
        {
            sort(nums.begin(), nums.end());
            while (k > 0)
            {
                nums[0] = -nums[0];
                k--;
            }
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};
