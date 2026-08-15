// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int maxPos = min(arrLen - 1, steps / 2 + 1);
        vector<long long> dp(maxPos + 1, 0);
        dp[0] = 1;
        for (int s = 0; s < steps; s++) {
            vector<long long> next(maxPos + 1, 0);
            for (int p = 0; p <= maxPos; p++) {
                if (dp[p] == 0) continue;
                next[p] = (next[p] + dp[p]) % MOD;
                if (p + 1 <= maxPos) next[p+1] = (next[p+1] + dp[p]) % MOD;
                if (p - 1 >= 0) next[p-1] = (next[p-1] + dp[p]) % MOD;
            }
            dp = next;
        }
        return (int)dp[0];
    }
};
