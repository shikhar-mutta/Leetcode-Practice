// Link: https://leetcode.com/problems/regular-expression-matching/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(n*m)
// Approach: dp[i][j] = does s[0..i) match p[0..j); '*' means zero occurrences (skip pat pair)
// or one-more occurrence (consume a char of s if it matches the preceding pattern char)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<char>> dp(n + 1, vector<char>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            if (p[j-1] == '*' && j >= 2) dp[0][j] = dp[0][j-2];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '*') {
                    bool zero = j >= 2 && dp[i][j-2];
                    bool one = j >= 2 && (p[j-2] == '.' || p[j-2] == s[i-1]) && dp[i-1][j];
                    dp[i][j] = zero || one;
                } else {
                    bool match = p[j-1] == '.' || p[j-1] == s[i-1];
                    dp[i][j] = match && dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
