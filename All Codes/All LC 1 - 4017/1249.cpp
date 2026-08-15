// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(n) for the stack to store the indices of the unmatched parentheses
    //    Approach:
    //     1. We will use a stack to keep track of the indices of the unmatched opening parentheses '(' in the string s.
    //     2. We will iterate through the string s and for each character, we will check if it is an opening parenthesis '(' or a closing parenthesis ')'.
    //     3. If it is an opening parenthesis '(', we will push its index onto the stack.
    //     4. If it is a closing parenthesis ')', we will check if the stack is not empty. If it is not empty, we will pop the top index from the stack, which means we have found a matching pair of parentheses. If the stack is empty, we will mark the current closing parenthesis ')' as invalid by replacing it with a special character (e.g., '*').
    //     5. After iterating through the string, we will mark any remaining unmatched opening parentheses '(' in the stack as invalid by replacing them with the special character (e.g., '*').
    //     6. Finally, we will construct the result string by skipping all the invalid characters (i.e., the special character '*')
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