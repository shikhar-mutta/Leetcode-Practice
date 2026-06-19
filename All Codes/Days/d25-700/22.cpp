// Link: https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<string> &res, string &current, int open, int close, int max)
    {
        if (current.length() == max * 2)
        {
            res.push_back(current);
            return;
        }

        if (open < max) // op para in less then max then we can add open para
        {
            current.push_back('('); // push open para
            backtrack(res, current, open + 1, close, max);
            current.pop_back(); // pop back to backtrack
        }
        if (close < open) // close para in less then open para in that case we can add close para
        {
            current.push_back(')'); // push close para
            backtrack(res, current, open, close + 1, max);
            current.pop_back(); // pop back to backtrack
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string current;
        backtrack(res, current, 0, 0, n);
        return res;
    }
};
