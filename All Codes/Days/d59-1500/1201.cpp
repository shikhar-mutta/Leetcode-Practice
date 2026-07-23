// Link: https://leetcode.com/problems/ugly-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(max(a,b,c)*n))
    // SC: O(1)
    // Approach:
    //  1. Use binary search to find the nth ugly number.
    //  2. Define a helper function count(x) that returns the number of ugly numbers less than or equal to x.
    //  3. Use the inclusion-exclusion principle to count the numbers divisible by a, b, or c.
    //  4. Perform binary search on the range [1, 2e9] to find the smallest number x such that count(x) >= n.
    //  5. Return x as the nth ugly number.
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
