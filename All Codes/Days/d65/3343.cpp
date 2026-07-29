// Link: https://leetcode.com/problems/count-number-of-balanced-permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10 * N * (9N/2)), SC: O(N^2)
// Approach: E = count of even index slots, O = count of odd index slots (O+E=n). Process digit
// values 0..9 in order; for digit d with multiplicity cnt[d], decide how many k of its copies go
// to even slots (rest to odd). The number of ways to place those k copies into the currently
// remaining even slots (and cnt[d]-k into remaining odd slots) is a product of binomial
// coefficients, folded directly into the DP transition — dp[cntE][sumE] tracks how many even
// slots are filled and their digit-sum so far. Answer = dp[E][totalSum/2] (needs totalSum even).
class Solution {
public:
    const long long MOD = 1e9+7;

    int countBalancedPermutations(string num) {
        int n = num.size();
        int cnt[10] = {};
        int totalSum = 0;
        for (char c : num) { cnt[c-'0']++; totalSum += c-'0'; }

        if (totalSum % 2 != 0) return 0;
        int target = totalSum / 2;
        int E = (n + 1) / 2, O = n / 2;

        int maxFact = n + 1;
        vector<long long> fact(maxFact+1), invFact(maxFact+1);
        fact[0] = 1;
        for (int i = 1; i <= maxFact; i++) fact[i] = fact[i-1] * i % MOD;
        auto power = [&](long long b, long long e) {
            long long r = 1; b %= MOD;
            while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
            return r;
        };
        invFact[maxFact] = power(fact[maxFact], MOD-2);
        for (int i = maxFact; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;
        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a || a < 0) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a-b] % MOD;
        };

        // dp[cntE][sumE]
        vector<vector<long long>> dp(E+1, vector<long long>(target+1, 0));
        dp[0][0] = 1;
        int processedTotal = 0;

        for (int d = 0; d < 10; d++) {
            int c = cnt[d];
            if (c == 0) continue;
            vector<vector<long long>> ndp(E+1, vector<long long>(target+1, 0));
            for (int cntE = 0; cntE <= E; cntE++) {
                for (int sumE = 0; sumE <= target; sumE++) {
                    if (!dp[cntE][sumE]) continue;
                    int cntO = processedTotal - cntE;
                    for (int k = 0; k <= c; k++) {
                        int ncntE = cntE + k, nsumE = sumE + d*k;
                        if (ncntE > E || nsumE > target) continue;
                        int remE = E - cntE, remO = O - cntO;
                        long long ways = C(remE, k) * C(remO, c-k) % MOD;
                        if (!ways) continue;
                        ndp[ncntE][nsumE] = (ndp[ncntE][nsumE] + dp[cntE][sumE] * ways) % MOD;
                    }
                }
            }
            dp = ndp;
            processedTotal += c;
        }

        return (int)dp[E][target];
    }
};
