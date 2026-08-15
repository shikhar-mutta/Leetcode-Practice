// Link: https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;

    long long modpow(long long base, long long exp) {
        base %= MOD;
        if (base < 0) base += MOD;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (__int128)result * base % MOD;
            base = (__int128)base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    int numberOfWays(int n, int x, int y) {
        int maxN = max(n, x) + 1;
        vector<long long> fact(maxN + 1), invfact(maxN + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) fact[i] = fact[i-1] * i % MOD;
        invfact[maxN] = modpow(fact[maxN], MOD - 2);
        for (int i = maxN; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
        };

        long long ans = 0;
        int kmax = min(n, x);
        for (int k = 1; k <= kmax; k++) {
            long long surj = 0;
            for (int i = 0; i <= k; i++) {
                long long term = C(k, i) * modpow(k - i, n) % MOD;
                if (i % 2 == 0) surj = (surj + term) % MOD;
                else surj = (surj - term % MOD + MOD) % MOD;
            }
            long long ways = C(x, k) * surj % MOD * modpow(y, k) % MOD;
            ans = (ans + ways) % MOD;
        }
        return (int)ans;
    }
};
