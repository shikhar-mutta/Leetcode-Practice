// Link: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n1 = word1.size();
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        int best = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (len == 2 ? 2 : dp[i+1][j-1] + 2);
                    if (i < n1 && j >= n1) best = max(best, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return best;
    }
};
