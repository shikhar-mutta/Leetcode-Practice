// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                for (int face = 1; face <= k && face <= t; face++) {
                    dp[i][t] = (dp[i][t] + dp[i-1][t-face]) % MOD;
                }
            }
        }
        return (int)dp[n][target];
    }
};
