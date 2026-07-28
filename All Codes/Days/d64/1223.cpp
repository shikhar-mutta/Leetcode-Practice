// Link: https://leetcode.com/problems/dice-roll-simulation/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 36)  SC: O(n * 6)
// Approach: dp[i][j] = number of length-i sequences ending in face j
// (streak constraint respected). dp[i][j] = totalOfLenI-1 minus the
// count of length-(i-1) sequences that already end with exactly
// rollMax[j] consecutive j's (since appending one more j would break
// the limit): that count is 1 if i-1==rollMax[j] (the all-j sequence),
// else the sum over k!=j of dp[i-1-rollMax[j]][k].
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(6, 0));
        vector<long long> total(n + 1, 0);
        for (int j = 0; j < 6; j++) dp[1][j] = 1;
        total[1] = 6;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                long long val = total[i - 1];
                int k = rollMax[j];
                if (i - 1 == k) {
                    val -= 1;
                } else if (i - 1 > k) {
                    long long invalid = total[i - 1 - k] - dp[i - 1 - k][j];
                    val -= ((invalid % MOD) + MOD) % MOD;
                }
                dp[i][j] = ((val % MOD) + MOD) % MOD;
                total[i] = (total[i] + dp[i][j]) % MOD;
            }
        }
        return (int)total[n];
    }
};
