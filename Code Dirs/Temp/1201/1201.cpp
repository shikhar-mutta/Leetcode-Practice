// Link: https://leetcode.com/problems/ugly-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        auto gcd = [](long long x, long long y)
        {
            while (y)
            {
                long long t = x % y;
                x = y;
                y = t;
            }
            return x;
        };
        auto lcm = [&](long long x, long long y)
        { return x / gcd(x, y) * y; };

        long long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c);
        long long abc = lcm(ab, c);

        // how many numbers in [1, x] are divisible by a, b, or c
        auto count = [&](long long x)
        {
            return x / a + x / b + x / c - x / ab - x / ac - x / bc + x / abc;
        };

        long long lo = 1, hi = 2e9;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return (int)lo;
    }
};
