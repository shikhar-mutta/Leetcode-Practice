// Link: https://leetcode.com/problems/three-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(n)), SC: O(1)
    //  Approach:
    //  1. A number n has exactly three positive divisors if and only if it is the square of a prime number. This is because the divisors of n are 1, the prime number itself, and n. Therefore, we can check if n is a perfect square and if its square root is a prime number. If both conditions are satisfied, then n has exactly three positive divisors.
    //  2. To check if a number is prime, we can iterate from 2 to the square root of the number and check if it is divisible by any of those numbers. If it is not divisible by any of them, then it is prime.
    //  3. If n is not a perfect square, then it cannot have exactly three positive divisors, so we can return false in that case.
    bool isThree(int n)
    {
        int r = (int)sqrt((double)n);
        if (r * r != n)
            return false;
        for (int d = 2; d * d <= r; ++d)
            if (r % d == 0)
                return false;
        return r > 1;
    }
};
