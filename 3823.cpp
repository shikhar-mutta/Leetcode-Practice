// Link: https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseByType(string s)
    {
        vector<char> letters, specials;
        for (char c : s)
        {
            if (isalpha(c))
                letters.push_back(c);
            else
                specials.push_back(c);
        }

        int li = letters.size() - 1, si = specials.size() - 1;
        for (char &c : s)
        {
            if (isalpha(c))
                c = letters[li--];
            else
                c = specials[si--];
        }
        return s;
    }
};