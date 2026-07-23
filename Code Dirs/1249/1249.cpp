// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        vector<int> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stk.push_back(i);
            else if (s[i] == ')')
            {
                if (!stk.empty())
                    stk.pop_back();
                else
                    s[i] = '*';
            }
        }
        for (int i : stk)
            s[i] = '*';
        string res;
        for (char c : s)
            if (c != '*')
                res += c;
        return res;
    }
};