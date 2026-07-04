// Link: https://leetcode.com/problems/distinct-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(n)
    // Approach: Dynamic Programming
    int numDistinct(string s, string t)
    {
        // dp[j] = #ways t[0..j) appears as a subsequence of the s-prefix
        // processed so far; j descends so each s char is used at most once.
        // unsigned: intermediate counts can overflow (cf. 518), final fits int
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // empty t matches one way
        for (int i = 0; i < m; i++)
            for (int j = min(i, n - 1); j >= 0; j--)
                if (s[i] == t[j])
                    dp[j + 1] += dp[j];
        return (int)dp[n];
    }
};
