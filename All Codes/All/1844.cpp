// Link: https://leetcode.com/problems/replace-all-digits-with-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string replaceDigits(string s)
    {
        // odd indices hold digits: replace with previous letter shifted forward
        for (int i = 1; i < (int)s.size(); i += 2)
            s[i] = s[i - 1] + (s[i] - '0');
        return s;
    }
};
