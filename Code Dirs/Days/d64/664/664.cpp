// Link: https://leetcode.com/problems/strange-printer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
//  Approach: interval DP. dp[i][j] = min turns to print s[i..j]. Base:
//  dp[i][i]=1. Default dp[i][j]=dp[i+1][j]+1 (print s[i] separately),
//  then for every k in (i,j] with s[k]==s[i], merge the print of s[i]
//  with s[k]'s print pass: dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k][j]).
class Solution
{
public:
    int dp[105][105];
    int solve(string &t, int i, int j)
    {
        int n = t.size();
        if (i == j)
        {
            return 1;
        }
        if (i > j)
        {
            return 1e8;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = 1e8;
        int take1 = 1 + solve(t, i + 1, j);
        mini = min(mini, take1);
        for (int k = i + 1; k <= j; k++)
        {
            if (t[i] == t[k])
            {
                int take2 = solve(t, i + 1, k - 1) + solve(t, k, j);
                mini = min(mini, take2);
            }
        }
        return dp[i][j] = mini;
    }
    int strangePrinter(string s)
    {
        int n = s.size();
        string t = "";
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] != s[i + 1])
            {
                t += s[i];
            }
        }
        t += s[n - 1];
        int sz = t.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(t, 0, sz - 1);
        return ans;
    }
};