// Link: https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for precomputation and O(log n) for each query due to bit manipulation and combinatorial calculations.
// SC: O(1) for precomputation and O(1) for each query
// Approach: The solution precomputes the binomial coefficients (nCk) for all combinations of n and k up to 50, which allows for efficient calculation of the number of integers with a specific popcount depth. It also precomputes the numbers that have a specific popcount depth for depths 1 to 4. For each query, it uses bit manipulation to count the number of valid integers less than or equal to n that have a popcount depth equal to k by iterating through the bits of n and using the precomputed values.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// @lc code=start
class Solution
{
    inline static long long nCk[50][50];
    inline static int nums_depth[4][50];

    inline static int _precomp = []()
    {
        for (int n = 0; n < 50; ++n)
        {
            nCk[n][0] = 1;
            for (int k = 1; k <= n; ++k)
                nCk[n][k] = nCk[n - 1][k] + nCk[n - 1][k - 1];
        }

        int idx[4]{};
        for (int n = 1; n < 50; ++n)
        {
            int d = 0;
            for (unsigned m = n; m > 1; m = popcount(m))
                ++d;
            nums_depth[d][idx[d]++] = n;
        }

        return 0;
    }();

public:
    long long popcountDepth(long long n, int k)
    {
        if (k == 0)
            return 1;
        if (k == 5)
            return 0;

        ++n;

        int *tar = nums_depth[k - 1];
        int num_bits = 64 - countl_zero(1ull * n);

        long long ans = k > 1 ? 0 : -1;

        int bits_left = 0;
        for (int i = num_bits - 1; i >= 0; --i)
        {
            if (!(n & (1ll << i)))
                continue;

            for (int *tar_bits = tar; *tar_bits && *tar_bits - bits_left <= i; ++tar_bits)
                ans += nCk[i][*tar_bits - bits_left];

            ++bits_left;
            if (*tar && *tar < bits_left)
                ++tar;
        }

        return ans;
    }
};
