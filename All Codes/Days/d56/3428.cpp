// Link: https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n) where n is the size of the nums
    // SC: O(n) where n is the size of the nums
    //  Approach:
    //  1. Sort the nums array in non-decreasing order.
    //  2. Precompute the factorials and their modular inverses up to n using Fermat's little theorem.
    //  3. Precompute the number of subsequences of size at most k that can be formed from the first i elements of the sorted nums array using dynamic programming
    //  4. Iterate through the sorted nums array and for each element, calculate its contribution to the final answer by multiplying it with the number of subsequences that can be formed from the elements
    //  5. Return the final answer modulo 10^9 + 7.
    int minMaxSums(vector<int> &nums, int k)
    {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> fact(n + 1), inv(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        long long b = fact[n], r = 1, e = MOD - 2;
        while (e)
        {
            if (e & 1)
                r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        inv[n] = r;
        for (int i = n; i > 0; i--)
            inv[i - 1] = inv[i] * i % MOD;
        auto C = [&](int a, int b) -> long long
        {
            if (b < 0 || b > a)
                return 0;
            return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
        };

        vector<long long> S(n);
        S[0] = 1;
        for (int i = 0; i + 1 < n; i++)
            S[i + 1] = (2 * S[i] - C(i, k - 1) + MOD) % MOD;

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + nums[i] % MOD * ((S[i] + S[n - 1 - i]) % MOD)) % MOD;
        return (int)ans;
    }
};
