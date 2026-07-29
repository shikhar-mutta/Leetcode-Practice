// Link: https://leetcode.com/problems/count-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s|), SC: O(|s|)
// Approach: for each word, distinct anagram count = len! / prod(charCount!). Precompute
// factorials and modular inverse factorials, multiply across all words.
class Solution {
public:
    const long long MOD = 1e9+7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int countAnagrams(string s) {
        int n = s.size();
        vector<long long> fact(n+1), invFact(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n] = power(fact[n], MOD-2);
        for (int i = n; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;

        long long ans = 1;
        int i = 0;
        while (i < n) {
            int cnt[26] = {};
            int j = i, len = 0;
            while (j < n && s[j] != ' ') { cnt[s[j]-'a']++; j++; len++; }
            long long ways = fact[len];
            for (int c = 0; c < 26; c++) ways = ways * invFact[cnt[c]] % MOD;
            ans = ans * ways % MOD;
            i = j + 1;
        }
        return (int)ans;
    }
};
