// Link: https://leetcode.com/problems/find-products-of-elements-of-big-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // count of numbers in [0,x] with bit b set
    long long countBitSet(long long x, int b) {
        if (x < 0) return 0;
        long long cycle = 1LL << (b + 1);
        long long half = 1LL << b;
        long long full = (x + 1) / cycle;
        long long rem = (x + 1) % cycle;
        return full * half + max(0LL, rem - half);
    }

    // sum_{i=1}^{x} popcount(i)
    long long countUpTo(long long x) {
        long long total = 0;
        for (int b = 0; b <= 50; b++) total += countBitSet(x, b);
        return total;
    }

    // sum_{i=1}^{x} (sum of set bit positions of i)
    long long bitSumUpTo(long long x) {
        long long total = 0;
        for (int b = 0; b <= 50; b++) total += (long long)b * countBitSet(x, b);
        return total;
    }

    // sum of the k smallest set-bit positions of x (k >= 1, k <= popcount(x))
    long long partialBitSum(long long x, long long k) {
        long long sum = 0;
        for (int b = 0; b <= 50 && k > 0; b++) {
            if (x & (1LL << b)) {
                sum += b;
                k--;
            }
        }
        return sum;
    }

    long long powmod(long long base, long long exp, long long mod) {
        if (mod == 1) return 0;
        long long r = 1; base %= mod;
        while (exp > 0) {
            if (exp & 1) r = r * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return r;
    }

    // S(idx) = sum of exponents of big_nums[0..idx] (0-indexed), -1 => 0
    long long expSumUpTo(long long idx) {
        if (idx < 0) return 0;
        long long lo = 1, hi = (long long)4e15;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countUpTo(mid) > idx) hi = mid;
            else lo = mid + 1;
        }
        long long x = lo;
        long long prevCount = countUpTo(x - 1);
        long long offsetWithinX = idx - prevCount; // 0-indexed
        return bitSumUpTo(x - 1) + partialBitSum(x, offsetWithinX + 1);
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            long long l = q[0], r = q[1], mod = q[2];
            long long totalExp = expSumUpTo(r) - expSumUpTo(l - 1);
            res.push_back((int)powmod(2, totalExp, mod));
        }
        return res;
    }
};
