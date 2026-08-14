// Link: https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = (i + 1) / 2; j <= i; j++) {
                if (dp[j - 1] != INT_MAX)
                    dp[i] = min(dp[i], dp[j - 1] + prices[j - 1]);
            }
        }
        return dp[n];
    }
};
