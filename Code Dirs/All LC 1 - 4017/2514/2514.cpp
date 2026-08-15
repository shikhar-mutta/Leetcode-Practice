// Link: https://leetcode.com/problems/count-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) {
            if (e & 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    int countAnagrams(string s) {
        int n = s.size();
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;

        stringstream ss(s);
        string word;
        long long ans = 1;
        while (ss >> word) {
            vector<int> cnt(26, 0);
            for (char c : word) cnt[c - 'a']++;
            long long denom = 1;
            for (int c : cnt) denom = denom * fact[c] % MOD;
            long long ways = fact[word.size()] * power(denom, MOD - 2) % MOD;
            ans = ans * ways % MOD;
        }
        return (int)ans;
    }
};
