// Link: https://leetcode.com/problems/wildcard-matching/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(n*m)
// Approach: dp[i][j] = does s[0..i) match p[0..j); '*' matches empty (dp[i][j-1]) or one more char of s (dp[i-1][j])
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<char>> dp(n + 1, vector<char>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
