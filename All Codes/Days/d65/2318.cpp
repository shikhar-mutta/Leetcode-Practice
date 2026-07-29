// Link: https://leetcode.com/problems/number-of-distinct-roll-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*36), SC: O(36)
// Approach: DP over last-two-values state (a,b); transition to c requires gcd(b,c)==1, c!=b, c!=a.
class Solution {
public:
    int distinctSequences(int n) {
        const int MOD = 1e9+7;
        if (n == 1) return 6;
        long long dp[7][7] = {};
        for (int a = 1; a <= 6; a++)
            for (int b = 1; b <= 6; b++)
                if (a != b && gcd(a,b) == 1) dp[a][b] = 1;

        for (int step = 3; step <= n; step++) {
            long long ndp[7][7] = {};
            for (int a = 1; a <= 6; a++)
                for (int b = 1; b <= 6; b++) {
                    if (!dp[a][b]) continue;
                    for (int c = 1; c <= 6; c++) {
                        if (c == a || c == b || gcd(b,c) != 1) continue;
                        ndp[b][c] = (ndp[b][c] + dp[a][b]) % MOD;
                    }
                }
            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;
        for (int a = 1; a <= 6; a++)
            for (int b = 1; b <= 6; b++)
                ans = (ans + dp[a][b]) % MOD;
        return (int)ans;
    }
};
