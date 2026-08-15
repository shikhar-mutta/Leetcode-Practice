// Link: https://leetcode.com/problems/longest-palindromic-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int k = i + 1, l = j - 1;
                    while (k < l && s[k] == s[i]) k++;
                    while (k < l && s[l] == s[i]) l--;
                    if (k < l) dp[i][j] = dp[k][l] + 2;
                    else if (k == l) dp[i][j] = 3;
                }
                dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j-1]});
            }
        }
        return dp[0][n-1];
    }
};
