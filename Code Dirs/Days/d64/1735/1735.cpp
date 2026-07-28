// Link: https://leetcode.com/problems/count-ways-to-make-array-with-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long MOD = 1e9 + 7;
    vector<long long> fact, inv_fact;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
    }
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        int maxN = 10014;
        fact.assign(maxN, 1);
        for (int i = 1; i < maxN; i++) fact[i] = fact[i-1] * i % MOD;
        inv_fact.assign(maxN, 1);
        inv_fact[maxN-1] = power(fact[maxN-1], MOD - 2);
        for (int i = maxN - 2; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;

        vector<int> res;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            long long ways = 1;
            for (int p = 2; (long long)p * p <= k; p++) {
                if (k % p == 0) {
                    int e = 0;
                    while (k % p == 0) { k /= p; e++; }
                    ways = ways * C(e + n - 1, n - 1) % MOD;
                }
            }
            if (k > 1) ways = ways * C(1 + n - 1, n - 1) % MOD;
            res.push_back((int)ways);
        }
        return res;
    }
};
