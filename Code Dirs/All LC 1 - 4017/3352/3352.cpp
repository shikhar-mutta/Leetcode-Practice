// Link: https://leetcode.com/problems/count-k-reducible-numbers-less-than-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const long long MOD = 1000000007;
        int L = s.size();

        vector<bool> isKRed(L + 1, false);
        for (int p = 1; p <= L; p++) {
            // one operation already converts x -> p, consuming 1 of the k budget
            int x = p, stepsRemaining = k - 1;
            while (x != 1 && stepsRemaining > 0) {
                x = __builtin_popcount(x);
                stepsRemaining--;
            }
            isKRed[p] = (x == 1);
        }

        vector<long long> fact(L + 1), invfact(L + 1);
        fact[0] = 1;
        for (int i = 1; i <= L; i++) fact[i] = fact[i-1] * i % MOD;
        auto modpow = [&](long long base, long long exp) {
            base %= MOD;
            long long result = 1;
            while (exp > 0) {
                if (exp & 1) result = result * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return result;
        };
        invfact[L] = modpow(fact[L], MOD - 2);
        for (int i = L; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a || a < 0) return 0;
            return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
        };

        long long ans = 0;

        // numbers with fewer than L bits (all shorter numbers automatically < n)
        for (int m = 1; m < L; m++) {
            for (int p = 1; p <= m; p++) {
                if (isKRed[p]) {
                    ans = (ans + C(m - 1, p - 1)) % MOD;
                }
            }
        }

        // numbers with exactly L bits, less than n, via branch points
        int onesBefore = 0;
        for (int i = 0; i < L; i++) {
            if (s[i] == '1') {
                if (i > 0) { // i==0 would create a leading zero (shorter number), already counted above
                    int remainingBits = L - 1 - i;
                    for (int p = 1; p <= L; p++) {
                        if (!isKRed[p]) continue;
                        int need = p - onesBefore;
                        if (need >= 0 && need <= remainingBits) {
                            ans = (ans + C(remainingBits, need)) % MOD;
                        }
                    }
                }
                onesBefore++;
            }
        }

        return (int)ans;
    }
};
