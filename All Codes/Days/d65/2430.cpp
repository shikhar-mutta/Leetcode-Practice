// Link: https://leetcode.com/problems/maximum-deletions-on-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N^2)
// Approach: lcp[i][j] = longest common prefix of s[i:] and s[j:] via DP from the back.
// dp[i] = max deletions starting at i = 1 + best dp[i+L] over lengths L where s[i:i+L]==s[i+L:i+2L].
class Solution
{
public:
    int helper(int i, vector<int> &dp, int n, string &s)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int curr = i;
        int val = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[curr] == s[j])
                curr++;
            else
                curr = i;
            if (curr == i && s[curr] == s[j])
                curr++;
            if (curr - i == j - curr + 1)
                val = max(val, 1 + helper(curr, dp, n, s));
        }
        return dp[i] = val;
    }
    int deleteString(string s)
    {
        int n = s.size();

        vector<int> dp(n, -1);
        return helper(0, dp, n, s);
    }
};
