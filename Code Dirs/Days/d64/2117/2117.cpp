// Link: https://leetcode.com/problems/abbreviating-the-product-of-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((right-left) * log(maxVal))  SC: O(1)
// Approach: strip every factor of 2 and 5 from each number, tracking total
// counts c2,c5 (trailing zero count = min(c2,c5)); the leftover excess factor
// (2^(c2-c5) or 5^(c5-c2)) gets multiplied back since it's part of the real
// digits. Track the last-5-digit suffix mod 1e5 and the leading digits via a
// running sum of log10 (numerically stable for the prefix). If the final
// significant-digit count is <=10, compute and print the exact value instead
// (tracked in parallel via a small-number fast path with continuous
// decimal-trailing-zero stripping).
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long c2 = 0, c5 = 0;
        long long suffixCore = 1;
        long double totalLog = 0;
        bool small = true;
        long long exactProduct = 1;
        long long exactZeros = 0;

        for (int i = left; i <= right; i++) {
            int x = i;
            while (x % 2 == 0) { x /= 2; c2++; }
            while (x % 5 == 0) { x /= 5; c5++; }
            suffixCore = (suffixCore * x) % 100000;
            totalLog += log10((long double)i);
            if (small) {
                exactProduct *= i;
                while (exactProduct % 10 == 0) { exactProduct /= 10; exactZeros++; }
                if (exactProduct > 100000000000LL) small = false;
            }
        }

        long long zeroCount = min(c2, c5);
        long long excess2 = c2 - c5, excess5 = c5 - c2;
        auto modpow = [&](long long base, long long e, long long mod) {
            long long r = 1; base %= mod;
            while (e > 0) { if (e & 1) r = r * base % mod; base = base * base % mod; e >>= 1; }
            return r;
        };
        long long suffixFinal = suffixCore;
        if (excess2 > 0) suffixFinal = suffixFinal * modpow(2, excess2, 100000) % 100000;
        if (excess5 > 0) suffixFinal = suffixFinal * modpow(5, excess5, 100000) % 100000;

        long long totalDigits = (long long)floor((double)totalLog) + 1;
        long long significantDigits = totalDigits - zeroCount;

        if (significantDigits <= 10 && small) {
            return to_string(exactProduct) + "e" + to_string(exactZeros);
        } else {
            long double fracPart = totalLog - floorl(totalLog);
            long double leadVal = powl(10.0L, fracPart + 4.0L);
            long long prefix5 = (long long)leadVal;
            char buf[16];
            snprintf(buf, sizeof(buf), "%05lld", suffixFinal);
            return to_string(prefix5) + "..." + string(buf) + "e" + to_string(zeroCount);
        }
    }
};
