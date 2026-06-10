// Link: https://leetcode.com/problems/is-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m). SC: O(1).
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        while (i < n && j < m)
        {
            while (j < m && s[i] != t[j])
                j++;

            if (j < m && s[i] == t[j])
            {
                i++;
                j++;
                continue;
            }
            if (j == m && i < n)
                return false;
        }

        if (i == n)
            return true;

        return false;
    }
};
