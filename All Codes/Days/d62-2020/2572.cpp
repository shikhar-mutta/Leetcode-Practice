// Link: https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^10 * 30) — fixed by the prime-mask range 2..30
// SC: O(2^10) for the subset-DP array
// Approach: for each value 2..30, compute its bitmask over the 10 primes <=30
// (mask=-1 if any prime divides it twice, i.e. not squarefree). Bitmask-DP
// dp[mask] = number of subsets of values (excluding 1s) whose combined prime
// mask is exactly `mask`, weighting each value's contribution by its frequency
// (0/1 knapsack per value, iterating masks high to low). Sum all dp[mask] to
// get squarefree-product subset count, multiply by 2^count(1) since each 1 can
// be freely included/excluded without affecting squarefree-ness, then subtract
// 1 to remove the empty subset.
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const long long MOD = 1000000007;
        int masks[31] = {0};
        int primes[] = {2,3,5,7,11,13,17,19,23,29};
        for (int v = 2; v <= 30; ++v) {
            int x = v, mask = 0;
            for (int i = 0; i < 10; ++i) {
                if (x % primes[i] == 0) {
                    x /= primes[i];
                    if (x % primes[i] == 0) { mask = -1; break; }
                    mask |= (1 << i);
                }
            }
            masks[v] = mask;
        }

        vector<int> cnt(31, 0);
        for (int x : nums) ++cnt[x];

        int full = 1 << 10;
        vector<long long> dp(full, 0);
        dp[0] = 1;
        for (int v = 2; v <= 30; ++v) {
            if (cnt[v] == 0 || masks[v] == -1) continue;
            int m = masks[v];
            for (int s = full - 1; s >= 0; --s)
                if ((s & m) == 0 && dp[s])
                    dp[s | m] = (dp[s | m] + dp[s] * cnt[v]) % MOD;
        }

        long long total = 0;
        for (long long x : dp) total = (total + x) % MOD;

        long long powTwo = 1;
        for (int i = 0; i < cnt[1]; ++i) powTwo = powTwo * 2 % MOD;

        total = total * powTwo % MOD;      // combine value-subsets with 1-choices
        total = (total - 1 + MOD) % MOD;   // remove the single empty subset

        return (int)total;
    }
};
