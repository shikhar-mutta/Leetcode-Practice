// Link: https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), SC: O(1)
// Approach:
//   1. The maximum value in the array is 2^p - 1
//   2. The second maximum value in the array is 2^p - 2
//   3. The number of pairs of elements that can be formed is (2^(p-1) - 1)
//   4. The minimum non-zero product can be calculated as (2^p - 1) * (2^p - 2)
// 5. The final answer is (2^p - 1) * (2^p - 2)^(2^(p-1) - 1) % (10^9 + 7)
class Solution
{
public:
    int minNonZeroProduct(int p)
    {
        const long long MOD = 1000000007;
        long long maxVal = (1LL << p) - 1;    // 2^p - 1
        long long base = (maxVal - 1) % MOD;  // 2^p - 2
        long long exp = (1LL << (p - 1)) - 1; // number of pairs
        return maxVal % MOD * modpow(base, exp, MOD) % MOD;
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