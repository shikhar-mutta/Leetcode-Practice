// Link: https://leetcode.com/problems/the-number-of-good-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> cnt(31, 0);
        for (int x : nums) cnt[x]++;

        vector<int> primeMask(31, -1);
        for (int v = 2; v <= 30; v++) {
            int x = v, mask = 0;
            bool ok = true;
            for (int i = 0; i < (int)primes.size(); i++) {
                int p = primes[i];
                if (x % p == 0) {
                    x /= p;
                    if (x % p == 0) { ok = false; break; }
                    mask |= (1 << i);
                }
            }
            if (ok) primeMask[v] = mask;
        }

        int full = 1 << primes.size();
        vector<long long> dp(full, 0);
        dp[0] = 1;
        for (int v = 2; v <= 30; v++) {
            if (primeMask[v] == -1 || cnt[v] == 0) continue;
            int pm = primeMask[v];
            for (int mask = full - 1; mask >= 0; mask--) {
                if (dp[mask] == 0) continue;
                if (mask & pm) continue;
                dp[mask | pm] = (dp[mask | pm] + dp[mask] * cnt[v]) % MOD;
            }
        }

        long long total = 0;
        for (int mask = 1; mask < full; mask++) total = (total + dp[mask]) % MOD;

        long long onesMultiplier = 1;
        for (int i = 0; i < cnt[1]; i++) onesMultiplier = onesMultiplier * 2 % MOD;

        return (int)(total * onesMultiplier % MOD);
    }
};
