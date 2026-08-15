// Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            long long p = 1;
            for (int k = 0; k < x; k++) p *= i;
            if (p > n) break;
            for (int s = n; s >= p; s--) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
