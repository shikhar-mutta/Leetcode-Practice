// Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * maxVal^2), SC: O(maxVal^2)
// Approach: dp[g1][g2] = number of ways to partition the processed prefix into (seq1, seq2,
// unused) with seq1's gcd = g1 (0 = empty) and seq2's gcd = g2. Each new element either stays
// unused, joins seq1 (updating its gcd), or joins seq2. Answer = sum of dp[g][g] for g>=1
// (both sequences non-empty with matching gcd) after processing everything.
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const long long MOD = 1e9+7;
        int maxVal = *max_element(nums.begin(), nums.end());
        int M = maxVal + 1;
        vector<vector<long long>> dp(M, vector<long long>(M, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> ndp = dp;
            for (int g1 = 0; g1 < M; g1++) {
                for (int g2 = 0; g2 < M; g2++) {
                    if (!dp[g1][g2]) continue;
                    int ng1 = (g1 == 0) ? x : __gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;
                    int ng2 = (g2 == 0) ? x : __gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int g = 1; g < M; g++) ans = (ans + dp[g][g]) % MOD;
        return (int)ans;
    }
};
