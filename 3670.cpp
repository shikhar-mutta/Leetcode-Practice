// Link: https://leetcode.com/problems/maximum-product-of-two-integers-with-no-common-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // SOS (max-over-subsets) DP. For each x, the best partner is the
    // largest value whose bits all fit inside ~x (so x & partner == 0).
    // O(B * 2^B + n) instead of O(n^2).
    long long maxProduct(vector<int> &nums)
    {
        int mx = 0; // find the largest value in nums
        for (int x : nums)
            mx = max(mx, x);

        int B = 1;
        while ((1 << B) <= mx) // find the number of bits needed to represent mx (mask)
            ++B;

        int SIZE = 1 << B, FULL = SIZE - 1;

        // dp[mask] = max value present whose set bits are a subset of mask.
        vector<int> dp(SIZE, -1);

        for (int x : nums)
            dp[x] = x; // value x is itself a submask of x

        for (int b = 0; b < B; ++b)
            for (int mask = 0; mask < SIZE; ++mask)
                if (mask & (1 << b))
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << b)]);

        long long ans = 0;
        for (int x : nums)
        {
            int best = dp[FULL ^ x]; // largest value disjoint from x
            if (best >= 0)
                ans = max(ans, (long long)x * best);
        }
        return ans;
    }
};
