// Link: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdll(long long a, long long b) { return b == 0 ? a : gcdll(b, a % b); }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = (long long)k * (*min_element(coins.begin(), coins.end()));

        auto countLE = [&](long long x) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcdll(l, coins[i]);
                        long long nl = l / g * coins[i];
                        if (nl > (long long)2e18) { overflow = true; break; }
                        l = nl;
                    }
                }
                if (overflow) continue;
                int bits = __builtin_popcount(mask);
                long long term = x / l;
                if (bits % 2 == 1) total += term;
                else total -= term;
            }
            return total;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
