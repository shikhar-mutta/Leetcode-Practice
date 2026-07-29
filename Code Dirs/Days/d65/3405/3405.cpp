// Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: choose which k of the (n-1) adjacent gaps are "equal" via C(n-1,k). The remaining
// (n-1-k) gaps must each differ from the previous element; the first element has m choices,
// each subsequent "different" transition has (m-1) choices. Total = C(n-1,k) * m * (m-1)^(n-1-k).
class Solution {
public:
    const long long MOD = 1e9+7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n-1) return 0;
        vector<long long> fact(n), invFact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n-1] = power(fact[n-1], MOD-2);
        for (int i = n-1; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;

        long long C = fact[n-1] * invFact[k] % MOD * invFact[n-1-k] % MOD;
        long long ans = C * m % MOD * power(m-1, n-1-k) % MOD;
        return (int)ans;
    }
};
