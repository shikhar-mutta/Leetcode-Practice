// Link: https://leetcode.com/problems/range-product-queries-of-powers/description/

#include <bits/stdc++.h>
using namespace std;

static constexpr int mod = 1e9 + 7, B30 = (1 << 30) % mod;

// TC: O(30) to build the bit-position prefix sums, O(log(30)) per query
// SC: O(30) for the set-bit exponent list
// Approach: n's set bits give the powers of 2 in "powers" (LSB to MSB);
// prefix sums of those bit positions let each query's total exponent
// (sum of 2^bit for bit in [l, r]) be computed in O(1). Since that
// exponent can be huge, 2^exp mod is computed by splitting exp into
// 30-bit chunks (2^30 mod precomputed as B30) combined via fast modPow,
// avoiding a direct 2^exp overflow.
class Solution {
public:
    static int modPow(long long x, int exp) {
        if (exp == 0)
            return 1;
        long long y = (exp & 1) ? x : 1;
        return modPow(x * x % mod, exp >> 1) * y % mod;
    }
    static int pow2mod(int exp) {
        if (exp < 30)
            return 1 << exp;
        auto [q, r] = div(exp, 30);
        long long B = modPow(B30, q);
        return B * (1 << r) % mod;
    }
    static vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int m = queries.size();
        bitset<30> B(n);
        vector<int> exp2;
        for (int i = 0; i < 30; i++)
            if (B[i])
                exp2.push_back(i);

        partial_sum(exp2.cbegin(), exp2.cend(), exp2.begin());

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            const int s = queries[i][0], e = queries[i][1];
            const int exp = exp2[e] - ((s == 0) ? 0 : exp2[s - 1]);
            ans[i] = pow2mod(exp);
        }
        return ans;
    }
};
