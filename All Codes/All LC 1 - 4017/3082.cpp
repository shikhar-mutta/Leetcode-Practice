// Link: https://leetcode.com/problems/find-the-sum-of-the-power-of-all-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(k)
// Approach: power of a subsequence with sum k equals 2^(n - length), one
// per subset of the remaining elements. Fold that weighting directly into
// a knapsack DP: dp[s] tracks weighted count of sum-s subsequences seen
// so far. For each num, dp[s] = 2*dp[s] + dp[s-num] (the 2x accounts for
// this element being freely excludable from any prior subsequence's
// "remaining" set), processed s from k down to 0. Answer is dp[k].
class Solution
{
public:
    int sumOfPower(vector<int> &nums, int k)
    {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int s = k; s >= 0; s--)
            {
                long long take = (s >= num) ? dp[s - num] : 0;
                dp[s] = (dp[s] * 2 + take) % MOD;
            }
        }
        return (int)dp[k];
    }
};
