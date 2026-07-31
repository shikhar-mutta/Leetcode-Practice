// Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k), SC: O(n * k)
// Approach: We can use dynamic programming to find the minimum number of changes required to make k semi-palindromes. We define a dp array where dp[i][ct] represents the minimum number of changes required to make ct semi-palindromes from the substring starting at index i. We also define a pal array to store the minimum number of changes required to make the substring from index i to index j a palindrome. We use a recursive function to calculate the minimum changes required for each substring and update the dp array accordingly. Finally, we return the value of dp[0][k] which represents the minimum number of changes required to make k semi-palindromes from the entire string.
class Solution
{
public:
    vector<vector<int>> dp;
    vector<vector<int>> pal;

    int cst(string &s, int i, int j)
    {
        int len = j - i + 1;

        if (len < 2)
            return 1e9;
        if (pal[i][j] != -1)
            return pal[i][j];

        int ans = 1e9;
        for (int d = 1; d < len; d++)
        {
            if (len % d == 0)
            {
                int ans2 = 0;

                for (int l = 0; l < d; l++)
                {
                    int le = i + l;
                    int ri = i + len - d + l;

                    while (le < ri)
                    {
                        if (s[le] != s[ri])
                            ans2++;

                        le += d;
                        ri -= d;
                    }
                }
                ans = min(ans, ans2);
            }
        }

        return pal[i][j] = ans;
    }

    int func(int i, int ct, string &s)
    {
        if (ct == 0)
        {
            return (i == s.size()) ? 0 : 1e9;
        }

        if (s.size() - i < ct * 2)
            return 1e9;

        if (dp[i][ct] != -1)
            return dp[i][ct];

        int ans = 1e9;
        for (int j = i + 1; j < s.size() - (ct - 1) * 2; j++)
        {
            int ans2 = cst(s, i, j);
            if (ans2 != 1e9)
            {
                ans = min(ans, ans2 + func(j + 1, ct - 1, s));
            }
        }

        return dp[i][ct] = ans;
    }

    int minimumChanges(string s, int k)
    {
        int n = s.size();

        dp.assign(n + 1, vector<int>(k + 1, -1));
        pal.assign(n + 1, vector<int>(n + 1, -1));

        return func(0, k, s);
    }
};