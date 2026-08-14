// Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const long long MOD = 1e9 + 7;
        vector<int> spf(maxValue + 1, 0);
        for (int i = 2; i <= maxValue; i++) {
            if (spf[i] == 0) {
                for (long long j = i; j <= maxValue; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        int maxN = n + 20;
        vector<long long> fact(maxN, 1), inv(maxN, 1);
        for (int i = 1; i < maxN; i++) fact[i] = fact[i-1] * i % MOD;
        auto power = [&](long long base, long long e, long long mod) {
            long long r = 1; base %= mod;
            while (e > 0) { if (e & 1) r = r * base % mod; base = base * base % mod; e >>= 1; }
            return r;
        };
        inv[maxN-1] = power(fact[maxN-1], MOD-2, MOD);
        for (int i = maxN-2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % MOD;
        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * inv[b] % MOD * inv[a-b] % MOD;
        };

        long long total = 0;
        for (int x = 1; x <= maxValue; x++) {
            int v = x;
            long long ways = 1;
            while (v > 1) {
                int p = spf[v];
                int e = 0;
                while (v % p == 0) { v /= p; e++; }
                ways = ways * C(e + n - 1, n - 1) % MOD;
            }
            total = (total + ways) % MOD;
        }
        return (int)total;
    }
};
