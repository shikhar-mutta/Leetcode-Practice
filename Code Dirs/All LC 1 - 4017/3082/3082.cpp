// Link: https://leetcode.com/problems/find-the-sum-of-the-power-of-all-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            vector<long long> ndp(k + 1, 0);
            for (int j = 0; j <= k; j++) {
                ndp[j] = dp[j] * 2 % MOD;
                if (j >= x) ndp[j] = (ndp[j] + dp[j - x]) % MOD;
            }
            dp = ndp;
        }
        return (int)dp[k];
    }
};
