// Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(n*k)
// Approach: this is the unsigned Stirling number of the first kind c(n,k):
// dp[i][j] = dp[i-1][j-1] + (i-1)*dp[i-1][j], since the tallest new stick is
// either newly visible (j-1 visible before) or hidden behind (i-1) taller ones.
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i-1][j-1] + (long long)(i - 1) * dp[i-1][j]) % MOD;
            }
        }
        return (int)dp[n][k];
    }
};
