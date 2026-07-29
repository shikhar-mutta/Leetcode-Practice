// Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(k)
// Approach: Use dynamic programming to count the number of ways to arrange n sticks such that exactly k sticks are visible. The recurrence relation is based on whether the tallest stick is placed at the end (which increases the visible count) or not (which does not change the visible count). We optimize space by using a 1D array to store only the current state of visible counts.
int dp[1005];
class Solution
{
public:
    inline static const auto init = []()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return 0;
    }();

    int rearrangeSticks(int n, int k)
    {
        if (k > n || k == 0)
            return 0;

        const int MOD = 1e9 + 7;

        // Vektor helyett a globális tömböt nullázzuk ki gyorsan k-ig
        for (int i = 0; i <= k; ++i)
            dp[i] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            // std::max és std::min lecserélése gyorsabb inline kifejezésekre
            int min_j = (1 > k - (n - i)) ? 1 : (k - (n - i));
            int max_j = (k < i) ? k : i;

            // Belső ciklus kibontás-barát formában
            for (int j = max_j; j >= min_j; --j)
            {
                long long current = 1LL * (i - 1) * dp[j];
                if (j > 1)
                {
                    current += dp[j - 1];
                }
                dp[j] = current % MOD;
            }
        }

        return dp[k];
    }
};
