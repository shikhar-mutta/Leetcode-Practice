// Link: https://leetcode.com/problems/count-ways-to-make-array-with-product/description/

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

    long long C(long long n, long long r, vector<long long>& fact, vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        int maxN = 10000 + 15;
        vector<long long> fact(maxN), invFact(maxN);
        fact[0] = 1;
        for (int i = 1; i < maxN; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[maxN-1] = power(fact[maxN-1], MOD - 2);
        for (int i = maxN - 2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        vector<int> res;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            long long ans = 1;
            for (int p = 2; (long long)p * p <= k; p++) {
                if (k % p == 0) {
                    int e = 0;
                    while (k % p == 0) { k /= p; e++; }
                    ans = ans * C(e + n - 1, n - 1, fact, invFact) % MOD;
                }
            }
            if (k > 1) {
                ans = ans * C(1 + n - 1, n - 1, fact, invFact) % MOD;
            }
            res.push_back((int)ans);
        }
        return res;
    }
};
