// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: dp[i][j] = min ASCII delete sum to equalize s1[i:] and s2[j:]. Base cases delete all remaining chars of one string; transition matches chars for free or deletes the cheaper option.
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = m-1; i >= 0; i--) dp[i][n] = dp[i+1][n] + s1[i];
        for (int j = n-1; j >= 0; j--) dp[m][j] = dp[m][j+1] + s2[j];
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j+1] + s2[j]);
            }
        }
        return dp[0][0];
    }
};
