// Link: https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))  SC: O(n)
// Approach: We can use a greedy approach to solve this problem. We can sort the segments in descending order of their binary value and then concatenate them to get the maximum value.
//  We can use a custom comparator to sort the segments in descending order of their binary value. We can then concatenate the segments to get the maximum value. We can use a modulo operation to avoid overflow.
class Solution
{
public:
    int maxValue(vector<int> &nums1, vector<int> &nums0)
    {
        // Pack each (n1, n0) pair into one 64-bit key so the default (no
        // comparator) sort applies: high 32 bits = ~n1 -> n1 descending,
        // low 32 bits = n0 -> n0 ascending. Matches the original ordering.
        int n = nums1.size();
        vector<unsigned long long> x;
        x.reserve(n);
        long long num_start1 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums0[i] == 0)
            {
                num_start1 += nums1[i];
                continue;
            }
            unsigned int n1 = (unsigned int)nums1[i];
            unsigned int n0 = (unsigned int)nums0[i];
            x.push_back(((unsigned long long)(0xFFFFFFFFu - n1) << 32) | n0);
        }
        sort(x.begin(), x.end());
        constexpr long long mod = 1000000007;

        auto pow2 = [](long long e)
        {
            long long r = 1, b = 2;
            for (; e > 0; e >>= 1)
            {
                if (e & 1)
                    r = r * b % mod;
                b = b * b % mod;
            }
            return r;
        };
        long long res = 0;
        auto appendOnes = [&](long long k)
        {
            long long p = pow2(k);
            res = (res * p + (p - 1 + mod)) % mod;
        };
        auto appendZeros = [&](long long k)
        { res = res * pow2(k) % mod; };

        appendOnes(num_start1);
        for (unsigned long long key : x)
        {
            appendOnes(0xFFFFFFFFu - (unsigned int)(key >> 32));
            appendZeros((unsigned int)(key & 0xFFFFFFFFu));
        }

        return (int)res;
    }
};
