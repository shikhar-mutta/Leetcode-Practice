// Link: https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(dividend)), SC: O(1)
    int divide(int dividend, int divisor)
    {
        int dividend_sign = dividend < 0 ? -1 : 1;
        int divisor_sign = divisor < 0 ? -1 : 1;
        long long dividend_abs = abs((long long)dividend);
        long long divisor_abs = abs((long long)divisor);
        long long quotient = dividend_sign * divisor_sign * (dividend_abs / divisor_abs);
        // Clamp to 32-bit range (e.g. INT_MIN / -1 = 2147483648 overflows int).
        if (quotient > INT_MAX)
            return INT_MAX;
        if (quotient < INT_MIN)
            return INT_MIN;
        return (int)quotient;
    }
};
