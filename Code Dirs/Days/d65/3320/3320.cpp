// Link: https://leetcode.com/problems/count-the-number-of-winning-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: DP over (round, net score bob-alice offset by n, Bob's last creature) — Bob may not
// repeat his previous creature. Each round's score delta against Alice's fixed creature is
// win(+1)/lose(-1)/tie(0), determined by (bob-alice+3)%3 (cyclic F>E>W>F beats relation).
// Answer = sum of final states with positive net score.
class Solution {
public:
    int delta(int bob, int alice) {
        int d = (bob - alice + 3) % 3;
        if (d == 1) return 1;
        if (d == 2) return -1;
        return 0;
    }

    int countWinningSequences(string s) {
        const long long MOD = 1e9+7;
        int n = s.size();
        auto enc = [](char c) { return c == 'F' ? 0 : (c == 'W' ? 1 : 2); };

        vector<vector<long long>> dp(3, vector<long long>(2*n+1, 0));
        int a0 = enc(s[0]);
        for (int c = 0; c < 3; c++) dp[c][n + delta(c, a0)] = 1;

        for (int i = 1; i < n; i++) {
            int ai = enc(s[i]);
            vector<vector<long long>> ndp(3, vector<long long>(2*n+1, 0));
            for (int c = 0; c < 3; c++) {
                int dl = delta(c, ai);
                for (int d = 0; d <= 2*n; d++) {
                    int nd = d + dl;
                    if (nd < 0 || nd > 2*n) continue;
                    long long sum = 0;
                    for (int prevC = 0; prevC < 3; prevC++) {
                        if (prevC == c) continue;
                        sum += dp[prevC][d];
                    }
                    ndp[c][nd] = sum % MOD;
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int c = 0; c < 3; c++)
            for (int d = n+1; d <= 2*n; d++)
                ans = (ans + dp[c][d]) % MOD;
        return (int)ans;
    }
};
