// Link: https://leetcode.com/problems/number-of-distinct-roll-sequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSequences(int n) {
        const long long MOD = 1e9 + 7;
        if (n == 1) return 6;

        vector<vector<long long>> dp(7, vector<long long>(7, 0));
        for (int a = 1; a <= 6; a++) {
            for (int b = 1; b <= 6; b++) {
                if (a != b && __gcd(a, b) == 1) dp[a][b] = 1;
            }
        }

        for (int step = 2; step < n; step++) {
            vector<vector<long long>> ndp(7, vector<long long>(7, 0));
            for (int a = 1; a <= 6; a++) {
                for (int b = 1; b <= 6; b++) {
                    if (dp[a][b] == 0) continue;
                    for (int c = 1; c <= 6; c++) {
                        if (c != a && c != b && __gcd(c, b) == 1) {
                            ndp[b][c] = (ndp[b][c] + dp[a][b]) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }

        long long total = 0;
        for (int a = 1; a <= 6; a++)
            for (int b = 1; b <= 6; b++)
                total = (total + dp[a][b]) % MOD;
        return (int)total;
    }
};
