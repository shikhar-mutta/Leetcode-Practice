// Link: https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) SC: O(n^2 * k)
//  Approach: interval DP dp[i][j][budget] = longest palindromic subsequence
//  achievable from s[i..j] with at most `budget` total cyclic-shift
//  operations. Either skip s[i] or s[j], or pair them together paying the
//  cyclic letter distance between them (min of forward/backward distance
//  on the 26-letter ring) and recurse inward with the reduced budget.
int f[201][201][201];
class Solution
{
public:
    int longestPalindromicSubsequence(string s, int k)
    {
        int n = s.size();
        for (int ck = 0; ck <= k; ck++)
            for (int i = 0; i < n; i++)
                f[i][i][ck] = 1;
        for (int ck = 0; ck <= k; ck++)
            for (int len = 2; len <= n; len++)
            {
                for (int l = 0; l + len - 1 < n; l++)
                {
                    int r = l + len - 1;
                    f[l][r][ck] = max(f[l + 1][r][ck], f[l][r - 1][ck]);
                    int d = abs(s[l] - s[r]);
                    int nk = ck - min(d, 26 - d);
                    if (nk >= 0)
                        f[l][r][ck] = max(f[l][r][ck], 2 + f[l + 1][r - 1][nk]);
                }
            }
        return f[0][n - 1][k];
    }
};