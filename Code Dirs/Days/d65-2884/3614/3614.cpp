// Link: https://leetcode.com/problems/process-string-with-special-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string s.
// SC: O(n) for storing the lens vector which keeps track of the length of the string after processing each character.
// Approach: The solution processes the string in two passes. In the first pass, it calculates the effective length of the string after applying the special operations (*, #, %). In the second pass, it traverses the string in reverse to determine the character at position k after all operations have been applied. The algorithm handles each special character according to its defined behavior and keeps track of the current length and position accordingly.
class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long len = 0;
        for (auto c : s)
        {
            if (c == '*')
            {
                if (len)
                {
                    len--;
                }
            }
            else if (c == '#')
            {
                len *= 2;
            }
            else if (c == '%')
            {
                continue;
            }
            else
            {
                len++;
            }
        }
        if (k + 1 > len)
        {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                len++;
            }
            else if (s[i] == '#')
            {
                if (k + 1 > (len + 1) / 2)
                {
                    k -= len / 2;
                }
                len = (len + 1) / 2;
            }
            else if (s[i] == '%')
            {
                k = len - k - 1;
            }
            else
            {
                if (k + 1 == len)
                {
                    return s[i];
                }
                else
                {
                    len--;
                }
            }
        }
        return '.';
    }
};
