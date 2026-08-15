// Link: https://leetcode.com/problems/palindrome-partitioning-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i+1][j-1] + (s[i] != s[j] ? 1 : 0);
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) dp[1][i] = cost[0][i];
        for (int p = 2; p <= k; p++) {
            for (int i = p - 1; i < n; i++) {
                for (int j = p - 2; j < i; j++) {
                    dp[p][i] = min(dp[p][i], dp[p-1][j] + cost[j+1][i]);
                }
            }
        }
        return dp[k][n-1];
    }
};
