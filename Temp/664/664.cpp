// Link: https://leetcode.com/problems/strange-printer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(n^2)
// Approach: interval DP; dp[i][j] = min turns to print s[i..j]. Base dp[i][i]=1. dp[i][j] = dp[i+1][j]+1 by default; if s[i]==s[k] for some k in (i,j], merge: dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]) (printing s[i] together with s[k]).
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                dp[i][j] = dp[i+1][j] + 1;
                for (int k = i+1; k <= j; k++) {
                    if (s[k] == s[i]) {
                        int left = (k-1 >= i+1) ? dp[i+1][k-1] : 0;
                        dp[i][j] = min(dp[i][j], left + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
