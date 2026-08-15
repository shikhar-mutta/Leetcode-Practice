// Link: https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for precomputation and O(log n) for each query due to bit manipulation and combinatorial calculations.
// SC: O(1) for precomputation and O(1) for each query
int pd[50];
int bits[5][100000], vs[100000];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pd[1] = 0;
    for (int i = 2; i < 50; ++i)
        pd[i] = 1 + pd[__builtin_popcount((unsigned)i)];
    return 0;
}();

inline int popdepth(long long u) { return u == 1 ? 0 : 1 + pd[__builtin_popcountll((unsigned long long)u)]; }

class Solution
{
public:
    vector<int> popcountDepth(vector<long long> &nums,
                              vector<vector<long long>> &queries)
    {
        int N = size(nums);
        for (int i = 0; i < 5; ++i)
            fill(bits[i], bits[i] + N, 0);
        for (int i = 0; i < N; ++i)
        {
            ++bits[vs[i] = popdepth(nums[i])][i];
            int r = i | (i + 1);
            if (r < N)
                for (int j = 0; j < 5; ++j)
                    bits[j][r] += bits[j][i];
        }

        vector<int> res;
        for (const auto &q : queries)
        {
            if (q[0] == 1)
            {
                int l = q[1], r = q[2], k = q[3];
                if (k == 5)
                {
                    res.push_back(0);
                    continue;
                }
                int *bit = bits[k], val = 0;
                for (; r >= 0; r = (r & (r + 1)) - 1)
                    val += bit[r];
                for (--l; l >= 0; l = (l & (l + 1)) - 1)
                    val -= bit[l];
                res.push_back(val);
            }
            else
            {
                int idx = q[1], val = popdepth(q[2]), prev = vs[idx];
                if (val == prev)
                    continue;
                int *bp = bits[prev], *bv = bits[val];
                for (int i = idx; i < N; i = i | (i + 1))
                    --bp[i], ++bv[i];
                vs[idx] = val;
            }
        }
        return res;
    }
};
