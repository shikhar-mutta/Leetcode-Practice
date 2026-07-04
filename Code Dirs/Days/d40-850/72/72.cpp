// Link: https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m). SC: O(n*m) + O(n+m) for recursion stack
// Approach : Recursion + Memoization
class Solution
{
public:
    int function(int i, int j, string &s1, string &s2,
                 vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = function(i - 1, j - 1, s1, s2, dp);
        else
        {
            return dp[i][j] = min(1 + function(i, j - 1, s1, s2, dp),
                                  min(1 + function(i - 1, j, s1, s2, dp),
                                      1 + function(i - 1, j - 1, s1, s2, dp)));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int i = 0; i <= m; i++)
            prev[i] = i;

        for (int i = 1; i <= n; i++)
        {
            cur[0] = i; // update everytime
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = prev[j - 1];

                else
                    cur[j] = 1 + min(prev[j - 1], min(cur[j - 1], prev[j]));
            }
            prev = cur;
        }
        return prev[m];
    }
};