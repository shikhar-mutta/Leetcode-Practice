// Link: https://leetcode.com/problems/count-ways-to-build-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(high)
// SC: O(high)
// Approach: dp[i] = number of ways to build a string of length i using
// blocks of "zero" zeros or "one" ones, with dp[0] = 1 as the base case.
// Each length sums contributions from appending a zero-block or a
// one-block to a shorter string. Sum dp[i] over all lengths in [low, high]
// to get strings whose length falls in the valid range.
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const long long MOD = 1000000007;
        vector<long long> dp(high + 1, 0);
        dp[0] = 1; // empty string: one way

        long long res = 0;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            if (i >= low)
                res = (res + dp[i]) % MOD;
        }
        return (int)res;
    }
};
