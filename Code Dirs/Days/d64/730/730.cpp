// Link: https://leetcode.com/problems/count-different-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: interval DP. For each pair of indices (i,j), compute the number of distinct palindromic subsequences in s[i..j].
//  Let dp[i][j] be the number of distinct palindromic subsequences in s[i..j]. If s[i] != s[j], then dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]. If s[i] == s[j], then we need to consider the characters between i and j. Let l be the index of the first occurrence of s[i] in s[i+1..j-1], and r be the index of the last occurrence of s[j] in s[i+1..j-1]. If there are no occurrences, then dp[i][j] = 2 * dp[i+1][j-1] + 2. If there is one occurrence, then dp[i][j] = 2 * dp[i+1][j-1] + 1. If there are more than one occurrences, then dp[i][j] = 2 * dp[i+1][j-1] - dp[l+1][r-1].
class Solution
{
    static constexpr auto M = 1000000007;

public:
    int countPalindromicSubsequences(string s)
    {
        const int n = s.size();
        vector<int> dp(n * n, 0);
        array<int, 4> prev{};
        array<int, 4> next{};
        for (int i = 0; i < n; i++)
        {
            dp[i * n + i] = 1;
            next[s[i] - 'a'] = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[i] == s[j])
                {
                    dp[i * n + j] = (2 * dp[(i - 1) * n + j + 1]) % M;
                    int l = next[s[i] - 'a'];
                    int r = prev[s[i] - 'a'];
                    if (l > r)
                        dp[i * n + j] += 2;
                    else if (l == r)
                        dp[i * n + j] += 1;
                    else
                    {
                        dp[i * n + j] =
                            (dp[i * n + j] - dp[(r - 1) * n + l + 1] + M) % M;
                    }
                }
                else
                {
                    dp[i * n + j] =
                        (dp[(i - 1) * n + j] + dp[i * n + j + 1]) % M;
                    dp[i * n + j] =
                        (dp[i * n + j] - dp[(i - 1) * n + j + 1] + M) % M;
                }
                next[s[j] - 'a'] = j;
            }
            prev[s[i] - 'a'] = i;
        }
        return dp[(n - 1) * n];
    }
};