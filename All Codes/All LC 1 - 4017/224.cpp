// Link: https://leetcode.com/problems/basic-calculator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(N)
    //   Approach:
    //   1. We can use a stack to keep track of the current result and sign. We can iterate through the input string and keep track of the current number, the current result, and the current sign. We can use a variable to store the current number and update it as we encounter digits.
    //   2. When we encounter a '+' or '-' operator, we can add the current number to the current result based on the current sign. We can then update the current sign to the new operator and reset the current number to 0. When we encounter a '(', we can push the current result and sign onto the stack and reset the current result and sign.
    //   3. When we encounter a ')', we can pop the sign and result from the stack and add the current result to the popped result based on the popped sign. We can continue this process until we reach the end of the string. Finally, we can return the current result.
    int calculate(string s)
    {
        stack<int> st;

        long long result = 0;
        long long number = 0;
        long long sign = 1;

        for (char c : s)
        {

            if (isdigit(c))
            {

                number = number * 10 + (c - '0');
            }

            else if (c == '+')
            {

                result += sign * number;
                number = 0;
                sign = 1;
            }

            else if (c == '-')
            {

                result += sign * number;
                number = 0;
                sign = -1;
            }

            else if (c == '(')
            {

                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (c == ')')
            {

                result += sign * number;
                number = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * number;

        return result;
    }
};