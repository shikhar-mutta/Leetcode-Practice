// Link: https://leetcode.com/problems/count-ways-to-build-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        long long ans = 0;
        for (int len = 1; len <= high; len++) {
            if (len >= zero) dp[len] = (dp[len] + dp[len - zero]) % MOD;
            if (len >= one) dp[len] = (dp[len] + dp[len - one]) % MOD;
            if (len >= low) ans = (ans + dp[len]) % MOD;
        }
        return (int)ans;
    }
};
