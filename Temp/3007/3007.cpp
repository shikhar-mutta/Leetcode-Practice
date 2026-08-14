// Link: https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBit(long long N, int bit) {
        long long cycle = 1LL << (bit + 1);
        long long half = 1LL << bit;
        long long full = (N + 1) / cycle;
        long long rem = (N + 1) % cycle;
        return full * half + max(0LL, rem - half);
    }

    long long price(long long N, int x) {
        long long total = 0;
        for (int j = x; j <= 63; j += x) {
            total += countBit(N, j - 1);
        }
        return total;
    }

    long long findMaximumNumber(long long k, int x) {
        long long lo = 1, hi = (long long)2e15;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (price(mid, x) <= k) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
