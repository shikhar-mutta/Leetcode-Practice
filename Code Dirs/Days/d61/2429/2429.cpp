// Link: https://leetcode.com/problems/minimize-xor/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), as we are using a constant amount of extra space for variables
// SC: O(1), as we are using a constant amount of extra space for variables
// Approach:
//   1. We first count the number of set bits in num2 using the builtin function __builtin_popcount(num2) and store it in the variable k.
//   2. We initialize a variable x to 0, which will be used to construct the final answer.
//  3. We iterate through the bits of num1 from the most significant bit (31) to the least significant bit (0) using a for loop. For each bit, we check if it is set in num1. If it is set, we set the corresponding bit in x and decrement k. We continue this process until we have set k bits in x or we have processed all bits of num1.
//  4. If we still have k bits left to set in x after processing all bits of num1, we iterate through the bits of x from the least significant bit (0) to the most significant bit (31) using another for loop. For each bit, we check if it is not set in x. If it is not set, we set the corresponding bit in x and decrement k. We continue this process until we have set k bits in x or we have processed all bits of x.
class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int k = __builtin_popcount(num2);
        int x = 0;
        for (int b = 31; b >= 0 && k > 0; --b)
        {
            if (num1 & (1 << b))
            {
                x |= (1 << b);
                --k;
            }
        }
        for (int b = 0; b < 32 && k > 0; ++b)
        {
            if (!(x & (1 << b)))
            {
                x |= (1 << b);
                --k;
            }
        }
        return x;
    }
};
