// Link: https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int numPrimes = primes.size();
        vector<long long> dp(1 << numPrimes, 0);
        dp[0] = 1;

        int ones = freq.count(1) ? freq[1] : 0;

        for (auto &[v, c] : freq) {
            if (v == 1) continue;
            int mask = 0;
            bool valid = true;
            int x = v;
            for (int i = 0; i < numPrimes && valid; i++) {
                int p = primes[i];
                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) { x /= p; cnt++; }
                    if (cnt > 1) { valid = false; break; }
                    mask |= (1 << i);
                }
            }
            if (!valid) continue;

            for (int m = (1 << numPrimes) - 1; m >= 0; m--) {
                if (dp[m] == 0) continue;
                if ((m & mask) == 0) {
                    dp[m | mask] = (dp[m | mask] + dp[m] * c) % MOD;
                }
            }
        }

        long long dpSum = 0;
        for (long long v : dp) dpSum = (dpSum + v) % MOD;

        long long onesMultiplier = 1;
        for (int i = 0; i < ones; i++) onesMultiplier = onesMultiplier * 2 % MOD;

        long long total = (dpSum * onesMultiplier - 1 + MOD) % MOD;
        return (int)total;
    }
};
