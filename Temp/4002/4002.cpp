// Link: https://leetcode.com/problems/count-valid-sequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b, long long mod) {
        long long res = 1; a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int countValidSequences(int n, int k) {
        int maxN = n + 5;
        vector<long long> fact(maxN), inv_fact(maxN);
        fact[0] = 1;
        for (int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[maxN - 1] = power(fact[maxN - 1], MOD - 2, MOD);
        for (int i = maxN - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

        auto nCr = [&](long long a, long long b) -> long long {
            if (b < 0 || b > a || a < 0) return 0;
            return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
        };

        long long total = nCr(n - 1, k - 1);
        long long allOdd = 0;
        if ((n - k) >= 0 && (n - k) % 2 == 0) {
            allOdd = nCr((n + k) / 2 - 1, k - 1);
        }
        long long ans = ((total - allOdd) % MOD + MOD) % MOD;
        return (int)ans;
    }
};
