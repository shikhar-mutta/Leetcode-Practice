// Link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long b, long long e, long long m) {
        long long r = 1; b %= m;
        while (e > 0) {
            if (e & 1) r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int d = abs(endPos - startPos);
        if (d > k || (k - d) % 2 != 0) return 0;
        int need = (k + d) / 2;

        vector<long long> fact(k + 1);
        fact[0] = 1;
        for (int i = 1; i <= k; i++) fact[i] = fact[i-1] * i % MOD;

        long long inv = power(fact[need] * fact[k - need] % MOD, MOD - 2, MOD);
        return (int)(fact[k] * inv % MOD);
    }
};
