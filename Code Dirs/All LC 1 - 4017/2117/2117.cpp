// Link: https://leetcode.com/problems/abbreviating-the-product-of-a-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long cnt2 = 0, cnt5 = 0;
        for (int i = left; i <= right; i++) {
            int x = i;
            while (x % 2 == 0) { cnt2++; x /= 2; }
            x = i;
            while (x % 5 == 0) { cnt5++; x /= 5; }
        }
        long long zeroCount = min(cnt2, cnt5);

        double sumLog = 0;
        for (int i = left; i <= right; i++) sumLog += log10((double)i);
        long long totalDigits = (long long)floor(sumLog) + 1;
        long long digitsNoZeros = totalDigits - zeroCount;

        long long budget5 = zeroCount, budget2 = zeroCount;
        long double prefix = 1.0L;
        const unsigned long long MOD = 100000000000000ULL;
        unsigned long long suffixMod = 1;
        for (int i = left; i <= right; i++) {
            long long x = i;
            while (budget5 > 0 && x % 5 == 0) { x /= 5; budget5--; }
            while (budget2 > 0 && x % 2 == 0) { x /= 2; budget2--; }
            prefix *= (long double)x;
            while (prefix >= 10.0L) prefix /= 10.0L;
            suffixMod = (suffixMod * (unsigned long long)x) % MOD;
        }

        if (digitsNoZeros <= 10) {
            ostringstream oss;
            oss << suffixMod << "e" << zeroCount;
            return oss.str();
        } else {
            long long prefixDigits = (long long)(prefix * 10000.0L);
            long long suffixDigits = suffixMod % 100000ULL;
            ostringstream oss;
            oss << prefixDigits << "..." << setw(5) << setfill('0') << suffixDigits << "e" << zeroCount;
            return oss.str();
        }
    }
};
