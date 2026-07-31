// Link: https://leetcode.com/problems/minimum-time-to-break-locks-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n) SC: O(2^n)
// Approach: Use dynamic programming with bitmasks. For each subset of locks,
// calculate the minimum time to break them in a specific order. The state
// is defined by the set of broken locks, and the transition considers
// adding each unbroken lock to the set.
class Solution
{
public:
    int findMinimumTime(vector<int> &strength, int k)
    {
        int n = strength.size();
        int timer = 0;
        int energy = 0;
        int x = 1;

        vector<int> dp((1 << n), INT_MAX);
        // state defn : dp[mask] = min time to break this much popcount(mask)
        // locks
        dp[0] = 0; // base case
        // transition :
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int i = __builtin_popcount(mask); // next index to be assigned
            if (i >= n)
                continue; // all are already assigned
            int cur_fac_x = 1 + (i * k);
            for (int j = 0; j < n; j++)
            {
                if (!(mask & (1 << j)))
                { // not broken
                    int new_mask = mask | (1 << j);
                    int cost_time_needed =
                        (strength[j] + cur_fac_x - 1) / cur_fac_x;
                    dp[new_mask] =
                        min(dp[new_mask], dp[mask] + cost_time_needed);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};