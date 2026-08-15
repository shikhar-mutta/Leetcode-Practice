// Link: https://leetcode.com/problems/nth-magical-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long l = (long long)a / __gcd(a, b) * b;
        long long lo = 1, hi = (long long)n * min(a, b);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = mid / a + mid / b - mid / l;
            if (count < n) lo = mid + 1;
            else hi = mid;
        }
        return (int)(lo % MOD);
    }
};
