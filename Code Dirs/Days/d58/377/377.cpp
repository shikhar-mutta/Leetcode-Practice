// Link: https://leetcode.com/problems/combination-sum-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * target) where n is the number of elements in nums and target is the target value
    // SC: O(target) where target is the target value
    // Approach:
    //   1. We will use dynamic programming to solve this problem.
    //   2. We will create a dp array of size target + 1 and initialize dp[0] = 1, as there is one way to make the target 0
    //   3. We will iterate through the dp array from 1 to target and for each value of t, we will iterate through the nums array and for each number x in nums
    //      we will check if x is less than or equal to t, if it is, we will add dp[t - x] to dp[t], as it represents the number of ways to make the target t by using the number x
    //   4. Finally, we will return dp[target] as the result, which represents the number of ways to make the target value
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; t++)
            for (int x : nums)
                if (x <= t)
                    dp[t] += dp[t - x];
        return (int)dp[target];
    }
};
