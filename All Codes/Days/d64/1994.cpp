// Link: https://leetcode.com/problems/the-number-of-good-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(30 * 2^10)  SC: O(2^10)
// Approach: only squarefree numbers 2..30 can appear in a good subset (any
// repeated prime factor breaks the product's squarefree property), and each
// distinct such value can be used at most once (picked from freq[v] indices).
// Bitmask DP over the 10 primes <=30 counts subsets per prime-mask; multiply
// the final total by 2^count(1) since 1s can be freely included/excluded.
class Solution
{
public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        const long long MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<long long> freq(31, 0);
        for (int x : nums)
            freq[x]++;

        vector<int> pmask(31, -1);
        for (int v = 2; v <= 30; v++)
        {
            int x = v, mask = 0;
            bool ok = true;
            for (int i = 0; i < (int)primes.size() && ok; i++)
            {
                if (x % primes[i] == 0)
                {
                    int cnt = 0;
                    while (x % primes[i] == 0)
                    {
                        x /= primes[i];
                        cnt++;
                    }
                    if (cnt > 1)
                        ok = false;
                    else
                        mask |= (1 << i);
                }
            }
            if (ok)
                pmask[v] = mask;
        }

        int full = 1 << primes.size();
        vector<long long> dp(full, 0);
        dp[0] = 1;
        for (int v = 2; v <= 30; v++)
        {
            if (pmask[v] == -1 || freq[v] == 0)
                continue;
            int pm = pmask[v];
            for (int mask = full - 1; mask >= 0; mask--)
            {
                if (dp[mask] == 0)
                    continue;
                if (mask & pm)
                    continue;
                dp[mask | pm] = (dp[mask | pm] + dp[mask] * freq[v]) % MOD;
            }
        }

        long long total = 0;
        for (int mask = 1; mask < full; mask++)
            total = (total + dp[mask]) % MOD;

        long long onesMul = 1;
        for (long long i = 0; i < freq[1]; i++)
            onesMul = onesMul * 2 % MOD;
        return (int)(total * onesMul % MOD);
    }
};
