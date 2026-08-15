// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    //  Approach:
    //  1. Use a stack to keep track of the current string being built.
    //  2. Iterate through each character in the input string.
    //  3. If the character is '(', push the current string onto the stack and clear the current string.
    //  4. If the character is ')', reverse the current string, pop the top string from the stack, and append the reversed current string to it.
    //  5. If the character is a letter, append it to the current string.
    //  6. After processing all characters, the current string will contain the final result.
    //  7. Return the current string as the result.
    string reverseParentheses(string s)
    {
        stack<string> st;
        string cur;

        for (char c : s)
        {
            if (c == '(')
            {
                st.push(cur);
                cur.clear();
            }
            else if (c == ')')
            {
                reverse(cur.begin(), cur.end());
                cur = st.top() + cur;
                st.pop();
            }
            else
            {
                cur += c;
            }
        }
        return cur;
    }
};