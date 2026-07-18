// Link: https://leetcode.com/problems/shortest-common-supersequence/description/

#include <bits/stdc++.h>
using namespace std;

short dp[1001][1001];
char buf[2002];
class Solution
{
public:
    // TC: O(m*n), SC: O(m*n)
    // Approach: Longest Common Subsequence
    string shortestCommonSupersequence(string str1, string str2)
    {
        if (str1 == str2)
            return str1;
        int m = str1.length(), n = str2.length();
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = m, j = n, p = 0;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                buf[p++] = str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                buf[p++] = str1[i - 1];
                i--;
            }
            else
            {
                buf[p++] = str2[j - 1];
                j--;
            }
        }
        while (i > 0)
            buf[p++] = str1[--i];
        while (j > 0)
            buf[p++] = str2[--j];
        reverse(buf, buf + p);
        return string(buf, p);
    }
};
