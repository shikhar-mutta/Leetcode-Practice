// Link: https://leetcode.com/problems/find-the-count-of-good-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1). SC: O(1). Precomputation is done in the constructor.
// Approach: Precompute the number of good integers for all lengths and all k values. Use DFS to generate all possible palindromic numbers and count the valid ones based on the divisibility condition.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
class Solution
{
    inline static long long ans[11][10];
    inline static const int _precompute = []()
    {
        long long fact[11]{1}, pow10[6]{1};
        int cnt[10]{};
        for (int i = 1; i <= 10; ++i)
            fact[i] = fact[i - 1] * i;
        for (int i = 1; i <= 5; ++i)
            pow10[i] = pow10[i - 1] * 10;
        unordered_set<long long> vis;
        auto dfs = [&fact, &pow10, &cnt, &vis](this auto &self, int n,
                                               long long l,
                                               long long r) -> void
        {
            if (n)
            {
                long long num = l * pow10[n / 2] + r;
                long long den = 1;
                long long hash = 0;
                for (int c : cnt)
                {
                    hash = hash * 11 + c;
                    den *= fact[c];
                }
                for (int k = 1; k <= 9; ++k)
                    if (num % k == 0)
                    {
                        long long hash_k = hash * 10 + k;
                        if (!vis.count(hash_k))
                        {
                            vis.insert(hash_k);
                            ans[n][k] += fact[n - 1] * (n - cnt[0]) / den;
                        }
                    }
            }
            if (n % 2 || n == 10)
                return;
            for (int i = n ? 0 : 1; i <= 9; ++i)
            {
                ++cnt[i];
                self(n + 1, l * 10 + i, r);
                ++cnt[i];
                self(n + 2, l * 10 + i, i * pow10[n / 2] + r);
                cnt[i] -= 2;
            }
        };
        dfs(0, 0, 0);
        return 0;
    }();

public:
    long long countGoodIntegers(int n, int k) { return ans[n][k]; }
};
