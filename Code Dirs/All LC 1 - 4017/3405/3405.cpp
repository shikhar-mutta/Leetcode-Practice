// Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e, long long mod) {
        long long r = 1; b %= mod;
        while (e > 0) {
            if (e & 1) r = r * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return r;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k >= n) return 0;
        int maxN = n;
        vector<long long> fact(maxN + 1), invFact(maxN + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[maxN] = power(fact[maxN], MOD - 2, MOD);
        for (int i = maxN; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        long long ways = C(n - 1, k);
        ways = ways * m % MOD;
        ways = ways * power(m - 1, n - 1 - k, MOD) % MOD;
        return (int)ways;
    }
};
