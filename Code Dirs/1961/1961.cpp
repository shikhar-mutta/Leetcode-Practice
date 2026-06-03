// Link: https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string ans = "";
        // Concatenate the words in the array and check if it matches the string s
        for (string word : words)
        {
            ans += word;
            if (ans == s) // If the concatenated string matches s, return true
                return true;
        }
        return false;
    }
};
