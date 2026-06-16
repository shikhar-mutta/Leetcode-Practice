// Link: https://leetcode.com/problems/faulty-keyboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string finalString(string s)
    {
        // 'i' is faulty: it reverses the typed text; other chars append normally
        string res;
        for (char c : s)
        {
            if (c == 'i')
                reverse(res.begin(), res.end());
            else
                res += c;
        }
        return res;
    }
};
