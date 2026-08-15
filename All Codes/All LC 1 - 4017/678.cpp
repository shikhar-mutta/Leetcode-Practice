// Link: https://leetcode.com/problems/valid-parenthesis-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool checkValidString(string s)
    {
        // Track the range [lo, hi] of possible counts of unmatched '('.
        int lo = 0, hi = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                lo++;
                hi++;
            }
            else if (c == ')')
            {
                lo--;
                hi--;
            }
            else
            {
                lo--;
                hi++;
            } // '*' could be ')', '(', or empty
            if (hi < 0)
                return false; // too many ')' even treating all '*' as '('
            if (lo < 0)
                lo = 0; // can't have negative open count
        }
        return lo == 0; // some assignment closes everything
    }
};
