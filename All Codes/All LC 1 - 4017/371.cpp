// Link: https://leetcode.com/problems/sum-of-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    //  Approach:
    //    1. Use bitwise operations to calculate the sum of two integers without using the '+' or '-' operators.
    //    2. The sum of two bits can be calculated using the XOR operation, while the carry can be calculated using the AND operation followed by a left shift.
    //    3. Repeat the process until there is no carry left, at which point the value of 'a' will be the final sum.
    //    4. The loop continues until 'b' becomes zero, indicating that there are no more carries to add.
    //    5. The final result is returned as the sum of the two integers.
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int carry = (unsigned int)a & (unsigned int)b;
            a = a ^ b;
            b = (int)(carry << 1);
        }
        return a;
    }
};
