// Link: https://leetcode.com/problems/count-different-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * 4)  SC: O(n^2)
// Approach: interval DP over the 4-letter alphabet 'a'-'d'. dp[i][j] =
// count of distinct palindromic subsequences in s[i..j]. For each
// letter c, find its leftmost occurrence l and rightmost occurrence r
// within [i,j]: if none, contributes 0; if l==r, contributes 1 ("c");
// if adjacent, contributes 2 ("c","cc"); otherwise contributes
// 2 + dp[l+1][r-1] (wrapping every inner palindrome with c on both sides,
// plus "c" and "cc" themselves), all mod 1e9+7.
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                long long total = 0;
                for (char c = 'a'; c <= 'd'; c++) {
                    int l = -1, r = -1;
                    for (int k = i; k <= j; k++) if (s[k] == c) { l = k; break; }
                    if (l == -1) continue;
                    for (int k = j; k >= i; k--) if (s[k] == c) { r = k; break; }
                    if (l == r) total += 1;
                    else if (l + 1 == r) total += 2;
                    else total += (2 + dp[l + 1][r - 1]) % MOD;
                }
                dp[i][j] = total % MOD;
            }
        }
        return (int)dp[0][n - 1];
    }
};
