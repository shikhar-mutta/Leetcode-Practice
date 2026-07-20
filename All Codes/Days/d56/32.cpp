// Link: https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string
    // SC: O(n) for the stack
    //  Approach:
    //     1. Use a stack to keep track of the indices of the characters in the string.
    //     2. Initialize the stack with -1 to handle the base case
    //     3. Iterate through the string, and for each character:
    //        a. If it's an opening parenthesis '(', push its index onto the stack.
    //        b. If it's a closing parenthesis ')', pop the top index from the stack. If the stack becomes empty, push the current index onto the stack. Otherwise, calculate the
    //           length of the valid substring by subtracting the current index from the top index of the stack and update the best length if it's greater than the previous best.
    //     4. Return the best length found after iterating through the string.
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int best = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    best = max(best, i - st.top());
            }
        }
        return best;
    }
};
