// Link: https://leetcode.com/problems/minimum-increments-for-target-multiples-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        static const auto INF = numeric_limits<int64_t>::max();

        const int n = size(nums);
        const int m = size(target);
        vector<int64_t> lcms(1 << m);
        for (int mask = 0; mask < (1 << m); ++mask) {
            int64_t l = 1;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    l = lcm(l, (int64_t)target[i]);
                }
            }
            lcms[mask] = l;
        }
        vector<int64_t> dp(1 << m, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            for (int mask = (1 << m) - 1; mask >= 0; --mask) {
                if (dp[mask] == INF) continue;
                const int new_mask = ((1 << m) - 1) - mask;
                for (int submask = new_mask; submask;
                     submask = (submask - 1) & new_mask) {
                    dp[mask | submask] =
                        min(dp[mask | submask],
                            dp[mask] + (x % lcms[submask]
                                            ? lcms[submask] - x % lcms[submask]
                                            : 0));
                }
            }
        }
        return dp[(1 << m) - 1];
    }
};
