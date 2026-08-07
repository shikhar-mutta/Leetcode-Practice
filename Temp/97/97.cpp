// Link: https://leetcode.com/problems/interleaving-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(n*m)
// Approach: dp[i][j] = can the first i+j chars of s3 be formed by interleaving first i of s1 and first j of s2
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != (int)s3.size()) return false;
        vector<vector<char>> dp(n + 1, vector<char>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                           (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[n][m];
    }
};
