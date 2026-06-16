// Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        // stack: if the new char completes "AB" or "CD" with the top, pop instead of pushing
        string st;
        for (char c : s)
        {
            if (!st.empty() && ((st.back() == 'A' && c == 'B') ||
                                (st.back() == 'C' && c == 'D')))
                st.pop_back();
            else
                st += c;
        }
        return st.size();
    }
};
