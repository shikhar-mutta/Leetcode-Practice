// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(steps^2)  SC: O(steps)
// Approach: DP over position, but since only steps/2 positions are ever
// reachable and useful (going further just wastes moves needed to
// return), cap the array width at min(arrLen, steps/2 + 1). Standard
// transition: dp[pos] = dp[pos-1] + dp[pos] + dp[pos+1] each step.
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const long long MOD = 1e9 + 7;
        int maxPos = min(arrLen, steps / 2 + 1);
        vector<long long> dp(maxPos, 0);
        dp[0] = 1;
        for (int s = 0; s < steps; s++) {
            vector<long long> ndp(maxPos, 0);
            for (int p = 0; p < maxPos; p++) {
                long long v = dp[p];
                if (p > 0) v = (v + dp[p - 1]) % MOD;
                if (p + 1 < maxPos) v = (v + dp[p + 1]) % MOD;
                ndp[p] = v;
            }
            dp = ndp;
        }
        return (int)dp[0];
    }
};
