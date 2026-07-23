// Link: https://leetcode.com/problems/clumsy-factorial/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the input number.
    // SC: O(n) where n is the input number.
    //  Approach:
    //  1. We will use a stack to store the intermediate results of the clumsy factorial.
    //  2. We will iterate from n to 1 and perform the operations in the order of multiplication, division, addition and subtraction.
    //  3. We will use a variable op to keep track of the current operation. The value of op will be 1 for multiplication, 2 for division, 3 for addition and 4 for subtraction.
    //  4. We will push the result of the current operation to the stack and continue to the next number.
    //  5. Finally, we will pop all the elements from the stack and return the sum of all the elements as the final result of the clumsy factorial.
    int clumsy(int n)
    {
        stack<int> st;
        int op = 1;
        st.push(n);
        for (int i = n - 1; i >= 1; i--)
        {
            if (op == 1)
            {
                int ans = st.top();
                st.pop();
                st.push(ans * i);
            }
            if (op == 2)
            {
                int ans = st.top();
                st.pop();
                st.push(ans / i);
            }
            if (op == 3)
            {
                st.push(i);
            }
            if (op == 4)
            {
                st.push(i * -1);
            }
            op++;
            if (op == 5)
                op = 1;
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
