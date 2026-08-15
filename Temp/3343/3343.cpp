// Link: https://leetcode.com/problems/count-number-of-balanced-permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int countBalancedPermutations(string num) {
        const long long MOD = 1000000007;
        int n = num.size();
        int cnt[10] = {0};
        int totalSum = 0;
        for (char c : num) { cnt[c-'0']++; totalSum += c-'0'; }

        if (totalSum % 2 != 0) return 0;
        int target = totalSum / 2;

        int numEven = (n + 1) / 2; // positions 0,2,4,...
        int numOdd = n / 2;

        int maxFact = n + 1;
        vector<long long> fact(maxFact + 1), invfact(maxFact + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxFact; i++) fact[i] = fact[i-1] * i % MOD;
        invfact[maxFact] = modpow(fact[maxFact], MOD - 2, MOD);
        for (int i = maxFact; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;

        // dp[usedEven][sum] = sum of 1/(prod e_d!) * 1/(prod (cnt[d]-e_d)!)
        vector<vector<long long>> dp(numEven + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;

        for (int d = 0; d < 10; d++) {
            int c = cnt[d];
            if (c == 0) continue;
            vector<vector<long long>> ndp(numEven + 1, vector<long long>(target + 1, 0));
            for (int usedEven = 0; usedEven <= numEven; usedEven++) {
                for (int s = 0; s <= target; s++) {
                    if (dp[usedEven][s] == 0) continue;
                    long long base = dp[usedEven][s];
                    for (int e = 0; e <= c; e++) {
                        int nUsedEven = usedEven + e;
                        if (nUsedEven > numEven) break;
                        long long ns = (long long)s + (long long)d * e;
                        if (ns > target) break;
                        long long weight = invfact[e] * invfact[c - e] % MOD;
                        ndp[nUsedEven][ns] = (ndp[nUsedEven][ns] + base * weight) % MOD;
                    }
                }
            }
            dp = move(ndp);
        }

        long long ans = dp[numEven][target] * fact[numEven] % MOD * fact[numOdd] % MOD;
        return (int)ans;
    }
};
