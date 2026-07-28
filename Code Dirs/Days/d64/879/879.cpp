// Link: https://leetcode.com/problems/profitable-schemes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(crimes * n * minProfit)  SC: O(n * minProfit)
// Approach: 0/1 knapsack DP over (membersUsed, profitAchieved), capping
// profit at minProfit (any profit >= minProfit counts the same). For
// each crime, iterate members/profit downward to avoid reuse.
// dp[m][p] = number of schemes using exactly m members with profit
// capped-at p; answer sums dp[m][minProfit] over all m.
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(minProfit + 1, 0));
        dp[0][0] = 1;

        int k = group.size();
        for (int c = 0; c < k; c++) {
            int g = group[c], p = profit[c];
            for (int m = n; m >= g; m--) {
                for (int pr = minProfit; pr >= 0; pr--) {
                    int newPr = min(minProfit, pr + p);
                    dp[m][newPr] = (dp[m][newPr] + dp[m - g][pr]) % MOD;
                }
            }
        }
        long long ans = 0;
        for (int m = 0; m <= n; m++) ans = (ans + dp[m][minProfit]) % MOD;
        return (int)ans;
    }
};
