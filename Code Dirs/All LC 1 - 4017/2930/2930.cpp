// Link: https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/

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

    int stringCount(int n) {
        long long total = power(26, n);
        long long A = power(25, n); // l==0
        long long C = power(25, n); // t==0
        long long B = (power(25, n) + (long long)n * power(25, n - 1)) % MOD; // e<=1
        long long AC = power(24, n);
        long long AB = (power(24, n) + (long long)n * power(24, n - 1)) % MOD;
        long long CB = (power(24, n) + (long long)n * power(24, n - 1)) % MOD;
        long long ABC = (power(23, n) + (long long)n * power(23, n - 1)) % MOD;

        long long bad = ((A + B + C) % MOD - (AB + AC + CB) % MOD + ABC % MOD) % MOD;
        long long ans = ((total - bad) % MOD + MOD) % MOD;
        return (int)ans;
    }
};
