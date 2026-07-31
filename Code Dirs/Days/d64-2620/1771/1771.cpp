// Link: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the string s
// SC: O(n^2) where n is the length of the string s
// Approach: We can use dynamic programming to find the longest palindromic subsequence in the concatenated string s = word1 + word2. We will create a 2D dp array where dp[i][j] represents the length of the longest palindromic subsequence in the substring s[i...j]. We will fill this dp array using the following rules:
// 1. If s[i] == s[j], then dp[i][j] = 2 + dp[i+1][j-1] (if i+1 <= j-1) else dp[i][j] = 2
// 2. If s[i] != s[j], then dp[i][j] = max(dp[i+1][j], dp[i][j-1])
// Finally, we will iterate through the dp array and find the maximum length of the palindromic subsequence that can be formed by taking characters from both word1 and word2. We will check for each character in word1 and word2 if they are equal, and if they are, we will update the maximum length of the palindromic subsequence accordingly
class Solution
{
public:
    int longestPalindrome(string word1, string word2)
    {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2;
                    if (i + 1 <= j - 1)
                        dp[i][j] += dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int m = word1.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = m; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    ans = max(ans, 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                }
            }
        }
        return ans;
    }
};
