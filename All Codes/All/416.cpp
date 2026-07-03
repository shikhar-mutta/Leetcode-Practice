// Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * target), SC: O(target)
    // 0/1 knapsack problem: DP[i][s] = can some subset of first i numbers sum to s
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2;
        // 0/1 knapsack: dp[s] = can some subset sum to s
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums)
        {
            for (int s = target; s >= x; s--)
                if (dp[s - x])
                    dp[s] = true;
            if (dp[target])
                return true;
        }
        return dp[target];
    }
};
