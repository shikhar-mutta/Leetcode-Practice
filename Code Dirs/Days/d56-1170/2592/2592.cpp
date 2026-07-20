// Link: https://leetcode.com/problems/maximize-greatness-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(1)
    // Approach:
    // 1. Sort the nums array.
    // 2. Use two pointers to find the maximum number of elements that can be greater than
    //    the elements in the original array.
    // 3. Return the result.
    int maximizeGreatness(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                ans++;
                i++;
            }
        }

        return ans;
    }
};