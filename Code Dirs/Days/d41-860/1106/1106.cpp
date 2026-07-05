// Link: https://leetcode.com/problems/parsing-a-boolean-expression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: Recursive Descent Parsing
class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        int i = 0;
        return parse(expression, i);
    }

private:
    // Recursive descent; i sits on the first char of a subexpression
    // and is one past its end when parse returns
    bool parse(const string &s, int &i)
    {
        char c = s[i++];
        if (c == 't')
            return true;
        if (c == 'f')
            return false;
        if (c == '!')
        {
            i++; // '('
            bool v = !parse(s, i);
            i++; // ')'
            return v;
        }
        // '&' or '|': fold subexpressions until ')'
        bool isAnd = (c == '&');
        bool v = isAnd;
        i++; // '('
        while (s[i] != ')')
        {
            if (s[i] == ',')
            {
                i++;
                continue;
            }
            bool sub = parse(s, i);
            v = isAnd ? (v && sub) : (v || sub);
        }
        i++; // ')'
        return v;
    }
};
