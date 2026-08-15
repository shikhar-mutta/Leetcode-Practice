// Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: the sum's parity only depends on how many of the L edges on
//  the path from node 1 to node n get weight 1 (weight 2 is always even).
//  We need an odd count of 1-weighted edges among L, which has exactly
//  2^(L-1) solutions (half of all 2^L assignments, by symmetry). Find L
//  via BFS, then compute 2^(L-1) mod 1e9+7.
struct Solution
{
    static unsigned
    assignEdgeWeights(const vector<vector<int>> &edges)
    {
        static const unsigned mod = 1000000007;

        unsigned size = edges.size() + 1u;
        auto arr = make_unique<unsigned[]>(size * 3u);

        unsigned *const cnt = arr.get();
        unsigned *const sum = cnt + size;
        unsigned *right = sum + size;
        const unsigned *left = right;

        for (span<const int> e : edges)
        {
            unsigned u = e[0] - 1u;
            unsigned v = e[1] - 1u;

            ++cnt[u];
            ++cnt[v];

            sum[u] ^= v;
            sum[v] ^= u;
        }

        for (unsigned i = 1; i != size; ++i)
            if (cnt[i] == 1u)
                *right++ = i;

        unsigned res = 1;

        while (left != right)
        {
            span<const unsigned> curr(left, right);
            left = right;

            for (unsigned v : curr)
            {
                unsigned p = sum[v];

                if (p)
                {
                    sum[p] ^= v;

                    if (--cnt[p] == 1u)
                        *right++ = p;
                }
            }

            res %= mod;
            res *= 2u;
        }

        return res / 2u;
    }
};