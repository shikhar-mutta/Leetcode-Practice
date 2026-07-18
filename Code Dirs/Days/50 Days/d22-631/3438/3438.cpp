// Link: https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string findValidPair(string s)
    {
        int freq[10] = {0};
        for (char c : s)
            freq[c - '0']++; // count each digit

        // a digit is "good" if its frequency equals its value
        auto good = [&](char c)
        { return freq[c - '0'] == c - '0'; };
        for (int i = 0; i + 1 < (int)s.size(); i++)
            if (s[i] != s[i + 1] && good(s[i]) && good(s[i + 1]))
                return s.substr(i, 2); // first valid adjacent pair
        return "";
    }
};
