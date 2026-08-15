// Link: https://leetcode.com/problems/count-ways-to-distribute-candies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToDistribute(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i-1][j-1] + (long long)j * dp[i-1][j]) % MOD;
            }
        }
        return (int)dp[n][k];
    }
};
