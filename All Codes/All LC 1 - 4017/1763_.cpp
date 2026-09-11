// Link: https://leetcode.com/problems/longest-nice-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        int n = s.size(), bestI = 0, bestLen = 0;
        for (int i = 0; i < n; i++)
        {
            int lower = 0, upper = 0; // bitmask of present lowercase and uppercase letters
            for (int j = i; j < n; j++)
            {
                if (islower(s[j]))
                    lower |= 1 << (s[j] - 'a');
                else
                    upper |= 1 << (s[j] - 'A');
                // nice when each present letter has both cases -> masks equal
                if (lower == upper && j - i + 1 > bestLen)
                {
                    bestLen = j - i + 1;
                    bestI = i;
                }
            }
        }
        return s.substr(bestI, bestLen);
    }
};
