// Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int numberOfSpecialChars(string word)
    {
        // track which letters appear in lower and upper form
        bool lower[26] = {false}, upper[26] = {false};
        for (char c : word)
            if (islower((unsigned char)c))
                lower[c - 'a'] = true;
            else
                upper[c - 'A'] = true;
        // special = letter present in BOTH cases
        int cnt = 0;
        for (int i = 0; i < 26; ++i)
            if (lower[i] && upper[i])
                cnt++;
        return cnt;
    }
};
