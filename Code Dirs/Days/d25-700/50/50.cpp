// Link: https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(1).
    double myPow(double x, int n)
    {
        long long exp = n;
        if (exp < 0) // Handle negative exponent by inverting x and making exp positive.
        {
            x = 1 / x; // x^(-n) == (1/x)^n
            exp = -exp;
        }

        double ans = 1.0;
        // Binary exponentiation: multiply in x^(2^k) for each set bit of exp.
        while (exp > 0)
        {
            if (exp & 1) // use binary bits to make answer. ex 5=101, 2^0(1) + 2^2(4) = 5
                ans *= x;
            x *= x;    // x becomes x^2, x^4, x^8, ...
            exp >>= 1; // Right shift exp to process the next bit. Divides exp by 2.
        }
        return ans;
    }
};
