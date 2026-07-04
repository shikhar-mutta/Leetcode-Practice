// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n)
    // Approach: Longest Palindromic Subsequence(LPS).
    int minInsertions(string s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1;
            int prev = 0;
            for (int j = i + 1; j < n; j++)
            {
                int temp = dp[j];
                if (s[i] == s[j])

                    dp[j] = 2 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return n - dp[n - 1];
    }
};
