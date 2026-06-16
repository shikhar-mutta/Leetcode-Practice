// Link: https://leetcode.com/problems/clear-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string clearDigits(string s)
    {
        // use the result string as a stack: a digit deletes the char before it
        string st;
        for (char c : s)
            if (isdigit((unsigned char)c))
                st.pop_back(); // remove closest left non-digit
            else
                st += c;
        return st;
    }
};
