// Link: https://leetcode.com/problems/handshakes-that-dont-cross/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int numPeople) {
        const long long MOD = 1e9 + 7;
        int n = numPeople / 2;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long sum = 0;
            for (int j = 0; j < i; j++) {
                sum = (sum + dp[j] * dp[i-1-j]) % MOD;
            }
            dp[i] = sum;
        }
        return (int)dp[n];
    }
};
