// Link: https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(1)
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int n = s.length();
        int start = 0, mxLen = 0;

        auto expand = [&](int l, int r) // expand towards both sides and check for palindrome
        {
            while (l >= 0 && r < n && s[l] == s[r])
            {

                if (r - l + 1 > mxLen)
                {
                    start = l;
                    mxLen = r - l + 1;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++)
        {
            expand(i, i);     // odd
            expand(i, i + 1); // even
        }
        return s.substr(start, mxLen);
    }
};