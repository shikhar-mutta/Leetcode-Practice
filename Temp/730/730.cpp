// Link: https://leetcode.com/problems/count-different-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * 4) SC: O(n^2)
// Approach: interval DP dp[i][j] = count of distinct palindromic subsequences in s[i..j]. For each of the 4 possible chars, find its first and last occurrence within [i,j]; if none, contributes 0; if exactly one, contributes 1 (the single char); if at least two, contributes 2 (open+close) plus the count of the sub-interval between them (avoiding double count via mod arithmetic).
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const long long MOD = 1e9+7;
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = 0;
                for (char c = 'a'; c <= 'd'; c++) {
                    int lo = -1, hi = -1;
                    for (int k = i; k <= j; k++) if (s[k] == c) { lo = k; break; }
                    for (int k = j; k >= i; k--) if (s[k] == c) { hi = k; break; }
                    if (lo == -1) continue;
                    if (lo == hi) dp[i][j] = (dp[i][j] + 1) % MOD;
                    else if (lo + 1 == hi) dp[i][j] = (dp[i][j] + 2) % MOD;
                    else dp[i][j] = (dp[i][j] + 2 + dp[lo+1][hi-1]) % MOD;
                }
            }
        }
        return (int)(dp[0][n-1] % MOD);
    }
};
