// Link: https://leetcode.com/problems/palindrome-partitioning-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: precompute cost[i][j] = min character changes to make
// s[i..j] a palindrome (two-pointer count of mismatches). Then partition
// DP: dp[i][p] = min total changes to split s[0..i) into p palindromic
// parts, transitioning dp[i][p] = min over j<i of dp[j][p-1] + cost[j][i-1].
class Solution
{
public:
    string s;
    int n;
    int dp[110][110];
    int need[110][110];

    int solve(int i, int j)
    {
        if (i >= j)
        {
            if (i == j)
                need[i][j] = 0;
            return 0;
        }

        if (need[i][j] != -1)
            return need[i][j];

        return need[i][j] = solve(i + 1, j - 1) + (s[i] != s[j]);
    }

    int sol(int i, int k)
    {
        if (i == n)
            return k == 0 ? 0 : INT_MAX / 2;

        if (k == 0)
            return INT_MAX / 2;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = INT_MAX / 2;

        for (int j = i; j < n; j++)
        {
            ans = min(ans, need[i][j] + sol(j + 1, k - 1));
        }

        return dp[i][k] = ans;
    }

    int palindromePartition(string str, int k)
    {
        s = str;
        n = s.size();

        memset(need, -1, sizeof(need));
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                solve(i, j);

        return sol(0, k);
    }
};