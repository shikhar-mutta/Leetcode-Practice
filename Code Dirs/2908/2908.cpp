// Link: https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // approach 1: use min_element
    // // TC: O(n^2) SC: O(1)
    // int minimumSum(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     int ans = INT_MAX;
    //     for (int i = 1; i < n - 1; i++)
    //     {
    //         int leftMin = *min_element(nums.begin(), nums.begin() + i);
    //         int rightMin = *min_element(nums.begin() + i + 1, nums.end());
    //         if (nums[i] > leftMin && nums[i] > rightMin)
    //             ans = min(ans, leftMin + nums[i] + rightMin);
    //     }
    //     return ans == INT_MAX ? -1 : ans;
    // }

    // approach 2: use precomputed arrays
    // TC: O(n) SC: O(n)
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, INT_MAX), right(n, INT_MAX);

        for (int i = 1; i < n; i++) // compute left min array
            left[i] = min(left[i - 1], nums[i - 1]);
        for (int i = n - 2; i >= 0; i--) // compute right min array
            right[i] = min(right[i + 1], nums[i + 1]);

        int mini = INT_MAX;
        for (int i = 1; i < n - 1; i++) // check for mountain triplet
            if (left[i] < nums[i] && nums[i] > right[i])
                mini = min(mini, left[i] + nums[i] + right[i]);
        return mini == INT_MAX ? -1 : mini;
    }
};
