// Link: https://leetcode.com/problems/delete-operation-for-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(n)
    // Approach: Longest Common Subsequence
    int minDistance(string word1, string word2)
    {
        // Keep the LCS in both strings, delete the rest:
        // answer = (m - LCS) + (n - LCS)
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0); // dp[j] = LCS(word1[0..i), word2[0..j))
        for (int i = 1; i <= m; i++)
        {
            int prev = 0; // dp[i-1][j-1]
            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prev + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return m + n - 2 * dp[n];
    }
};
