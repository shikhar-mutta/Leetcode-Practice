// Link: https://leetcode.com/problems/wildcard-matching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(1)
    // Approach: Two pointer approach
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size())
        {
            if (j < p.size() && (p[j] == '?' || p[j] == s[i]))
            {
                i++;
                j++;
            }
            else if (j < p.size() && p[j] == '*')
            {
                star = j;
                match = i;
                j++;
            }
            else if (star != -1)
            {
                j = star + 1;
                match++;
                i = match;
            }
            else
            {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*')
            j++;

        return j == p.size();
    }
};