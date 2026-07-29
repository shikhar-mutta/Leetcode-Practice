// Link: https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: for each k = number of stages actually used (1..min(n,x)), count ways: choose which
// k of the x stages via C(x,k); assign performers onto those k stages surjectively (every used
// stage nonempty) via inclusion-exclusion sum_{i=0}^{k} (-1)^i C(k,i) (k-i)^n; then award each of
// the k bands an independent score in [1,y] via y^k. Sum over all k.
class Solution {
public:
    const long long MOD = 1e9+7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD; if (b < 0) b += MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int numberOfWays(int n, int x, int y) {
        int maxN = max(n, x) + 1;
        vector<long long> fact(maxN+1), invFact(maxN+1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[maxN] = power(fact[maxN], MOD-2);
        for (int i = maxN; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a-b] % MOD;
        };

        long long ans = 0;
        int kMax = min(n, x);
        for (int k = 1; k <= kMax; k++) {
            long long surj = 0;
            for (int i = 0; i <= k; i++) {
                long long term = C(k, i) * power(k - i, n) % MOD;
                if (i % 2 == 0) surj = (surj + term) % MOD;
                else surj = (surj - term % MOD + MOD) % MOD;
            }
            long long ways = C(x, k) * surj % MOD * power(y, k) % MOD;
            ans = (ans + ways) % MOD;
        }
        return (int)ans;
    }
};
