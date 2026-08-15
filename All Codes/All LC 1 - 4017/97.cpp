// Link: https://leetcode.com/problems/interleaving-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) - where m is the length of s1 and n is the length of s2. We fill a 2D DP table of size (m+1) x (n+1).
    // SC: O(n) - We use a 1D DP array of size (n+1) to store the results for the current row, which reduces the space complexity from O(m*n) to O(n).
    // Approach:
    //  1. Check if the lengths of s1 and s2 add up to the length of s3. If not, return false.
    //  2. If the length of s1 is less than the length of s2, swap them to ensure that s1 is always the longer string. This allows us to use a 1D DP array of size (n+1) instead of a 2D DP table.
    //  3. Initialize a 1D DP array of size (n+1) with all values set to false. Set dp[0] to true, as an empty s1 and s2 can form an empty s3.
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l)
            return false;

        if (m < n)
            return isInterleave(s2, s1, s3);

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; ++j)
        {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; ++i)
        {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j)
            {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n];
    }
};
