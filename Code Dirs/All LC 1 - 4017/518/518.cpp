// Link: https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(amount * coins.size())  SC: O(amount)
// Approach: unbounded knapsack counting combinations - iterate coins
// outside, amounts inside, to avoid counting permutations separately
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int a = c; a <= amount; a++) {
                dp[a] += dp[a - c];
            }
        }
        return (int)dp[amount];
    }
};
