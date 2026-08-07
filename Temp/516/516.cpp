// Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: interval DP - dp[l][r] = longest palindromic subsequence in
// s[l..r]; extend by matching ends or take best of excluding one end
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) dp[l][r] = (len == 2 ? 2 : dp[l+1][r-1] + 2);
                else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};
