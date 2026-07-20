// Link: https://leetcode.com/problems/find-the-value-of-the-partition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n)
    // SC: O(1)
    //  Approach:
    //  1. Sort the array in ascending order.
    //  2. Initialize a variable s to store the minimum difference between adjacent elements.
    //  3. Iterate through the sorted array and calculate the difference between adjacent elements.
    //  4. Update s with the minimum difference found.
    //  5. Return the value of s as the result.
    int findValueOfPartition(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int s = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            s = min(nums[i + 1] - nums[i], s);
        }
        return s;
    }
};
