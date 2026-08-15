// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1]))
                    isPal[i][j] = true;
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            for (int len = k; i + len <= n; len++) {
                if (isPal[i][i+len-1]) {
                    dp[i+len] = max(dp[i+len], dp[i] + 1);
                    break;
                }
            }
        }
        return dp[n];
    }
};
