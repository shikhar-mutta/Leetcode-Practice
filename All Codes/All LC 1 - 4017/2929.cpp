// Link: https://leetcode.com/problems/distribute-candies-among-children-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) – only arithmetic operations, no loops
// SC: O(1) – constant extra space
// Approach: Inclusion-Exclusion on stars-and-bars.
// Total ways to split n into 3 non-negative parts = C(n+2, 2).
// Subtract cases where ≥1 child exceeds limit (fix that child at limit+1,
// remaining = n-(limit+1)), add back over-subtracted cases where ≥2 children
// exceed limit, remove triple-exceed. nCr2(x) = C(x,2) = x*(x-1)/2,
// returns 0 when x < 2 (invalid). Result = S0 - S1 + S2 - S3.
class Solution
{
public:
    // Helper function to calculate nC2 = n * (n - 1) / 2
    long long nCr2(long long n)
    {
        if (n < 2)
            return 0;
        return n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit)
    {
        long long total = 0;

        // S0: Unrestricted ways to distribute n candies among 3 children
        long long S0 = nCr2(n + 2);

        // S1: At least 1 child gets >= limit + 1 candies
        long long S1 = 3 * nCr2(n - limit + 1);

        // S2: At least 2 children get >= limit + 1 candies
        long long S2 = 3 * nCr2(n - 2LL * limit);

        // S3: All 3 children get >= limit + 1 candies
        long long S3 = nCr2(n - 3LL * limit - 1);

        // Principle of Inclusion-Exclusion
        total = S0 - S1 + S2 - S3;

        return total;
    }
};