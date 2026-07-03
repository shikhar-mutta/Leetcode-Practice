// Link: https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * amount), SC: O(amount)
    // Approach: DP(a) = min(DP(a - c) + 1 for c in coins)
    int coinChange(vector<int> &coins, int amount)
    {
        // unbounded knapsack: dp[a] = min coins to make amount a
        const int INF = INT_MAX / 2;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int c : coins)
            for (int a = c; a <= amount; a++)
                dp[a] = min(dp[a], dp[a - c] + 1);
        return dp[amount] >= INF ? -1 : dp[amount];
    }
};
