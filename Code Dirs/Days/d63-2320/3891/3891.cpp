// Link: https://leetcode.com/problems/minimum-increase-to-maximize-special-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: dp[i] = min increase to make nums[0..i] valid, with nums[i] being a special index.
//  We can compute dp[i] from dp[i-2] and dp[i-1], since we only need to consider the previous two elements to ensure that nums[i] is greater than its neighbors. We can also keep track of the minimum increase needed for both even and odd indices separately, and return the minimum of the two at the end.
class Solution
{
public:
    long long minIncrease(vector<int> &nums)
    {
        int64_t dp = 0;
        if (size(nums) % 2)
        {
            for (int i = 1; i + 1 < size(nums); i += 2)
            {
                dp += max((max(nums[i - 1], nums[i + 1]) + 1) - nums[i], 0);
            }
            return dp;
        }
        int64_t dp2 = 0;
        for (int i = 1; i + 1 < size(nums); i += 2)
        {
            dp += max((max(nums[i - 1], nums[i + 1]) + 1) - nums[i], 0);
            dp2 += max((max(nums[i], nums[i + 2]) + 1) - nums[i + 1], 0);
            dp2 = min(dp2, dp);
        }
        return dp2;
    }
};