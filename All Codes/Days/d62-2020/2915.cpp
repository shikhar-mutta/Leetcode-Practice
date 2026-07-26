// Link: https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/

// TC: O(n * target)
// SC: O(target) for the dp array
// Approach: DP where dp[s] = max length of subsequence with sum s. For each number,
// update dp backwards to avoid reusing same element. Return dp[target] if valid.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;

        for (int num : nums)
        {
            // Traverse backwards to avoid using same element twice
            for (int s = target; s >= num; s--)
            {
                if (dp[s - num] != -1)
                {
                    dp[s] = max(dp[s], dp[s - num] + 1);
                }
            }
        }

        return dp[target];
    }
};
