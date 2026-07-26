// Link: https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for prefix/suffix minimum arrays
// Approach: precompute the minimum value up to each index from the left and
// from the right. For each possible middle index, if both adjacent-side
// minimums are smaller than nums[i], use them to form the minimum mountain
// triplet sum.
class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> leftMin(n), rightMin(n);

        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        int ans = INT_MAX;

        for (int i = 1; i < n - 1; i++)
        {
            if (leftMin[i - 1] < nums[i] && rightMin[i + 1] < nums[i])
            {
                ans = min(ans, leftMin[i - 1] + nums[i] + rightMin[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
