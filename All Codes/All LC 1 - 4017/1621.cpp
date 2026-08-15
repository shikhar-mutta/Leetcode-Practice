// Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + k)
// SC: O(1)
//  Approach:
//         1. Use combinatorial mathematics to calculate the number of ways to choose k non-overlapping line segments from n points.
//         2. The number of ways to choose k non-overlapping line segments from n points is given by the formula C(n + k - 1, 2 * k) where C is the binomial coefficient.
//         3. Calculate the binomial coefficient using modular arithmetic to avoid overflow and return the result.
class Solution
{
public:
    int numberOfSets(int n, int k)
    {
        const long long MOD = 1000000007;
        int N = n + k - 1, R = 2 * k;
        if (R > N)
            return 0;

        long long num = 1, den = 1;
        for (int i = 0; i < R; ++i)
        {
            num = num * ((N - i) % MOD) % MOD;
            den = den * ((i + 1) % MOD) % MOD;
        }
        return num * modpow(den, MOD - 2, MOD) % MOD;
    }

private:
    long long modpow(long long b, long long e, long long m)
    {
        long long r = 1;
        b %= m;
        while (e)
        {
            if (e & 1)
                r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }
};
