// Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long b, long long e, long long m) {
        long long r = 1; b %= m;
        while (e > 0) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; }
        return r;
    }

    int numberOfSets(int n, int k) {
        int m = n - 1 + k;
        int r = 2 * k;
        vector<long long> fact(m + 1);
        fact[0] = 1;
        for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * i % MOD;
        long long inv = power(fact[r] * fact[m - r] % MOD, MOD - 2, MOD);
        long long ans = fact[m] * inv % MOD;
        return (int)ans;
    }
};
