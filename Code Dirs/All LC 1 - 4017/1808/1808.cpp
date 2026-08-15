// Link: https://leetcode.com/problems/maximize-number-of-nice-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int maxNiceDivisors(int n) {
        if (n <= 3) return n;
        long long res;
        if (n % 3 == 0) res = power(3, n / 3);
        else if (n % 3 == 1) res = power(3, n / 3 - 1) * 4 % MOD;
        else res = power(3, n / 3) * 2 % MOD;
        return (int)res;
    }
};
