// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    //    Approach:
    //    1. Use a stack to evaluate the reverse polish notation expression.
    //    2. Iterate through each token in the input vector.
    //    3. If the token is an operator (+, -, *, /), pop the top two elements from the stack, perform the operation, and push the result back onto the stack.
    //    4. If the token is a number, convert it to an integer and push it onto the stack.
    //    5. After processing all tokens, the final result will be the only element left in the stack, which is returned as the output.
    //    Note: This solution assumes that the input is a valid reverse polish notation expression and that division between two integers should truncate toward zero.
    int evalRPN(vector<string> &tokens)
    {
        vector<int> st;
        for (auto &tok : tokens)
        {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
            {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                if (tok == "+")
                    st.push_back(a + b);
                else if (tok == "-")
                    st.push_back(a - b);
                else if (tok == "*")
                    st.push_back(a * b);
                else
                    st.push_back(a / b);
            }
            else
            {
                st.push_back(stoi(tok));
            }
        }
        return st.back();
    }
};
