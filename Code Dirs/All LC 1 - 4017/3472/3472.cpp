// Link: https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        // dp[i][j][c] = LPS length of s[i..j] with budget c
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

        for (int i = 0; i < n; i++)
            for (int c = 0; c <= k; c++) dp[i][i][c] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int diff = abs(s[i] - s[j]);
                int cost = min(diff, 26 - diff);
                for (int c = 0; c <= k; c++) {
                    int best = 0;
                    if (i + 1 <= j) best = max(best, dp[i + 1][j][c]);
                    if (i <= j - 1) best = max(best, dp[i][j - 1][c]);
                    int inner = (i + 1 <= j - 1) ? dp[i + 1][j - 1][c] : 0;
                    if (s[i] == s[j]) {
                        best = max(best, inner + 2);
                    } else if (c >= cost) {
                        int innerC = (i + 1 <= j - 1) ? dp[i + 1][j - 1][c - cost] : 0;
                        best = max(best, innerC + 2);
                    }
                    dp[i][j][c] = best;
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
