// Link: https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m). SC: O(n). Where n is the amount and m is the number of coins.
// Approach: Dynamic Programming
class Solution
{
public:
    int mod = 1e9 + 7;
    int change(int amount, vector<int> &coins)
    {
        // Outer loop over coins => each combination counted once (order ignored)
        // unsigned: intermediate counts can exceed 2^63; addition mod 2^64 is
        // exact and the final answer fits in int, so wraparound is harmless
        vector<unsigned long long> dp(amount + 1, 0); // dp[j] = #combinations making j
        dp[0] = 1;
        for (int c : coins)
            for (int j = c; j <= amount; j++)
                dp[j] += dp[j - c];
        return (int)dp[amount];
    }
};
