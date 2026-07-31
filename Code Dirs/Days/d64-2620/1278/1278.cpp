// Link: https://leetcode.com/problems/palindrome-partitioning-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: precompute cost[i][j] = min character changes to make
// s[i..j] a palindrome (two-pointer count of mismatches). Then partition
// DP: dp[i][p] = min total changes to split s[0..i) into p palindromic
// parts, transitioning dp[i][p] = min over j<i of dp[j][p-1] + cost[j][i-1].
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= min(i, k); p++) {
                for (int j = p - 1; j < i; j++) {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};
