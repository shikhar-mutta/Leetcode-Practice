// Link: https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(amount * coins.size())  SC: O(amount)
// Approach: bottom-up DP, dp[a] = min coins to make amount a
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                if (c <= a && dp[a - c] != INT_MAX) dp[a] = min(dp[a], dp[a - c] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
