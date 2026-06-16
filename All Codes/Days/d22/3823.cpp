// Link: https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string reverseByType(string s)
    {
        string letters, specials;
        for (char c : s)
            (isalpha((unsigned char)c) ? letters : specials) += c;
        
        int li = letters.size() - 1, si = specials.size() - 1;
        string res;
        res.reserve(s.size());
        for (char c : s)
            res += isalpha((unsigned char)c) ? letters[li--] : specials[si--];
        return res;
    }
};
