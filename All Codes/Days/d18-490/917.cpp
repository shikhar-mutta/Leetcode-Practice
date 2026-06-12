// Link: https://leetcode.com/problems/reverse-only-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(n).
    string reverseOnlyLetters(string s)
    {
        auto getOnlyLetters = [](const string &s)
        {
            string ans;
            for (char c : s)
                if (isalpha(c))
                    ans += c;
            return ans;
        };
        string ans = getOnlyLetters(s);
        int j = ans.size() - 1;
        for (int i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                s[i] = ans[j--];
        return s;
    }
};
