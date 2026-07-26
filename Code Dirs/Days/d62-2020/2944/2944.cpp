// Link: https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) – for each i, inner loop runs up to i iterations (i+1..2i+1)
// SC: O(n)   – dp array of size n+2
// Approach: Reverse DP. dp[i] = min coins to acquire all fruits from i..n.
// Buying fruit i (1-indexed) costs prices[i-1] and grants fruits i+1..2i
// for free, meaning the next fruit to pay for can be any j in [i+1, 2i+1].
// dp[i] = prices[i-1] + min(dp[i+1..min(n+1, 2i+1)]).
// Base: dp[n+1] = 0. Answer = dp[1].
class Solution
{
public:
    int minimumCoins(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n + 2, INT_MAX);
        dp[n + 1] = 0;

        for (int i = n; i >= 1; --i)
        {
            int res = INT_MAX;
            for (int j = i + 1; j <= min(n + 1, 2 * i + 1); ++j)
            {
                res = min(res, dp[j]);
            }
            dp[i] = prices[i - 1] + res;
        }

        return dp[1];
    }
};