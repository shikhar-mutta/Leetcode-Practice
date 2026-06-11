// Link: https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int cnt = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                cnt++;
                if (cnt > 1)
                    ans += ch;
            }
            else
            {
                if (cnt > 1)
                    ans += ch;
                cnt--;
            }
        }
        return ans;
    }
};
