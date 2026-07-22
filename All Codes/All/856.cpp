// Link: https://leetcode.com/problems/score-of-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string s. We iterate through each character of the string once.
    // SC: O(n) in the worst case, where n is the length of the input string s. This is because we use a stack to keep track of the scores, and in the worst case, we may need to store all the scores in the stack.
    // Approach:
    //  1. We use a stack to keep track of the scores of the parentheses. We initialize the stack with a 0 to represent the score of the outermost parentheses.
    //  2. We iterate through each character of the input string s. If we encounter an opening parenthesis '(', we push a 0 onto the stack to represent the score of the new inner parentheses. If we encounter a closing parenthesis ')', we pop the top score from the stack, calculate the score of the current parentheses based on the popped score, and add it to the score of the outer parentheses (the new top of the stack).
    //  3. Finally, we return the score of the outermost parentheses, which is the top value of the stack.
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);
        for (char c : s)
        {
            if (c == '(')
            {
                st.push(0);
            }
            else
            {
                int val = st.top();
                st.pop();
                int score = val == 0 ? 1 : 2 * val;
                st.top() += score;
            }
        }
        return st.top();
    }
};
