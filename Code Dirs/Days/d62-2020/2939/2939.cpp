// Link: https://leetcode.com/problems/maximum-xor-product/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – iterate over n bits once
// SC: O(1) – only ax, bx counters
// Approach: Greedy bit manipulation. Bits above position n are fixed (copied
// from a and b). For each bit i from n-1 down to 0:
//   - If a and b have the same bit → set it in both ax and bx (XOR gives 1
//     for both, maximizing product).
//   - If bits differ → assign the bit to whichever of ax/bx is currently
//     smaller to balance and maximize the product (larger × smaller is
//     maximized when values are as close as possible).
// Finally return (ax % MOD) * (bx % MOD) % MOD.
class Solution
{
public:
    static constexpr int MOD = 1'000'000'007;

    int maximumXorProduct(long long a, long long b, int n)
    {
        long long ax = (a >> n) << n;
        long long bx = (b >> n) << n;

        for (int i = n - 1; i >= 0; --i)
        {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;

            if (x == y)
            {
                ax |= 1LL << i;
                bx |= 1LL << i;
            }
            else if (ax > bx)
            {
                bx |= 1LL << i;
            }
            else
            {
                ax |= 1LL << i;
            }
        }

        ax %= MOD;
        bx %= MOD;
        return (int)(ax * bx % MOD);
    }
};
