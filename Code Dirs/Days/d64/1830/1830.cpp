// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 26)  SC: O(n)
// Approach: count how many permutations of the multiset are lexicographically
// smaller than s (its rank), which equals the min adjacent-swap distance to
// the sorted string. At each position, sum over smaller available characters
// c: (m-1)! / (product of remaining counts factorial with one c removed),
// computed via modular inverse factorials, then remove s[i] and continue.
class Solution {
    const long long MOD = 1e9 + 7;
    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }
public:
    int makeStringSorted(string s) {
        int n = s.size();
        vector<long long> fact(n + 1), invfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invfact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;

        vector<long long> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        long long invFactProd = 1;
        for (int c = 0; c < 26; c++) invFactProd = invFactProd * invfact[cnt[c]] % MOD;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int m = n - i;
            long long smallerSum = 0;
            for (int c = 0; c < s[i] - 'a'; c++) smallerSum += cnt[c];
            long long term = fact[m-1] * invFactProd % MOD * (smallerSum % MOD) % MOD;
            ans = (ans + term) % MOD;
            int c = s[i] - 'a';
            invFactProd = invFactProd * cnt[c] % MOD;
            cnt[c]--;
        }
        return (int)ans;
    }
};
