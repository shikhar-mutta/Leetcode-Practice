// Link: https://leetcode.com/problems/delete-operation-for-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: find LCS length via DP; answer is (m-lcs)+(n-lcs) deletions needed.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = word1[i-1]==word2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
        int lcs = dp[m][n];
        return (m-lcs)+(n-lcs);
    }
};
