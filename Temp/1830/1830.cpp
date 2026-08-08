// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/description/

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

    int makeStringSorted(string s) {
        int n = s.size();
        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        int counts[26] = {0};
        for (char c : s) counts[c - 'a']++;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int smaller = 0;
            for (int c = 0; c < s[i] - 'a'; c++) smaller += counts[c];

            int remaining = n - i - 1;
            long long ways = fact[remaining];
            for (int c = 0; c < 26; c++) ways = ways * invFact[counts[c]] % MOD;

            ans = (ans + (long long)smaller * ways) % MOD;
            counts[s[i] - 'a']--;
        }
        return (int)ans;
    }
};
