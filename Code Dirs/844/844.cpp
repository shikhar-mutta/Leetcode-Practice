// Link: https://leetcode.com/problems/backspace-string-compare/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m), SC: O(n + m)
    bool backspaceCompare(string s, string t)
    {
        string a, b;
        for (char c : s)
            if (c == '#' && !a.empty())
                a.pop_back();
            else if (c != '#')
                a += c;
        for (char c : t)
            if (c == '#' && !b.empty())
                b.pop_back();
            else if (c != '#')
                b += c;

        return a == b;
    }
};