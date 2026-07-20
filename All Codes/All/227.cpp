// Link: https://leetcode.com/problems/basic-calculator-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(1)
    //  Approach:
    //  1. We can use a single pass approach to solve this problem. We can iterate through the input string and keep track of the current number, the last number, and the current operator. We can use a variable to store the current number and update it as we encounter digits.
    //  2. When we encounter an operator, we can perform the operation based on the last operator and update the last number accordingly. We can also update the current operator to the new operator and reset the current number to 0. We can continue this process until we reach the end of the string. Finally, we can return the sum of the last number and the current number as the final result.
    //  3. We can use a variable to store the current number and update it as we encounter digits. We can also use a variable to store the last number and update it based on the last operator. We can use a variable to store the current operator and update it as we encounter new operators. We can continue this process until we reach the end of the string. Finally, we can return the sum of the last number and the current number as the final result.
    int calculate(string s)
    {

        int curr = 0, last = 0;
        int ans = 0;
        char op = '+';
        s.push_back(op);

        for (const char &c : s)
        {
            if (c == ' ')
                continue;
            if (isdigit(c))
                curr = (curr * 10) + (c - '0');
            else
            {
                if (op == '+' || op == '-')
                {
                    ans += last;
                    last = (op == '+') ? curr : -curr;
                }
                else if (op == '*')
                    last = last * curr;
                else if (op == '/')
                    last = last / curr;
                op = c;
                curr = 0;
            }
        }

        return ans + last;
    }
};