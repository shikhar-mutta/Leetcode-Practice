// Link: https://leetcode.com/problems/maximize-number-of-nice-divisors/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log primeFactors)  SC: O(1)
// Approach: classic "integer break" — product is maximized by splitting into
// as many 3's as possible; remainder 1 becomes a 4 (2*2), remainder 2 stays as is.
class Solution
{
    const long long MOD = 1e9 + 7;
    long long power(long long b, long long e)
    {
        long long r = 1;
        b %= MOD;
        while (e)
        {
            if (e & 1)
                r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    int maxNiceDivisors(int primeFactors)
    {
        if (primeFactors <= 3)
            return primeFactors;
        int q = primeFactors / 3, r = primeFactors % 3;
        long long res;
        if (r == 0)
            res = power(3, q);
        else if (r == 1)
            res = power(3, q - 1) * 4 % MOD;
        else
            res = power(3, q) * 2 % MOD;
        return (int)res;
    }
};
