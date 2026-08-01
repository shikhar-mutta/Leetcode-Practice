// Link: https://leetcode.com/problems/number-of-effective-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^B + n * B)  SC: O(2^B + B) where B = number of bits in the largest number in nums
// Approach: Let B = number of bits in the largest number in nums. For each subsequence, we can represent it as a bitmask of length B, where the i-th bit is set if there is at least one number in the subsequence with the i-th bit set. We can count the number of subsequences for each bitmask using dynamic programming. The number of effective subsequences is then the sum of the counts of all bitmasks that have an odd number of bits set.
constexpr int mod = 1000000007;
int pow2[100001], cnts[1 << 20];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pow2[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        pow2[i] = (pow2[i - 1] * 2) % mod;
    return 0;
}();

class Solution
{
public:
    int countEffective(vector<int> &nums)
    {
        int str = 0, B = 0, bidx[20];
        for (int n : nums)
            str |= n;
        while (str)
            bidx[__builtin_ctz(str)] = B++, str &= str - 1;

        int S = 1 << B;
        fill(cnts, cnts + S, 0);
        for (int n : nums)
        {
            int m = 0;
            while (n)
                m |= 1 << bidx[__builtin_ctz(n)], n &= n - 1;
            ++cnts[m];
        }

        for (int i = 0; i < B; ++i)
            for (unsigned m = 0; m < S; ++m)
                if (m & (1 << i))
                {
                    cnts[m] += cnts[m ^ (1 << i)];
                }

        long long res = 0;
        for (unsigned m = 0; m < S - 1; ++m)
        {
            int p = (B - popcount(m)) & 1;
            res += (p + p - 1) * pow2[cnts[m]];
        }
        res %= mod;
        if (res < 0)
            res += mod;
        return res;
    }
};
