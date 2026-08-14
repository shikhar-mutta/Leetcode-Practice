// Link: https://leetcode.com/problems/maximum-and-sum-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int bits = 2 * numSlots;
        vector<int> dp(1 << bits, -1);
        dp[0] = 0;
        int best = 0;
        for (int mask = 0; mask < (1 << bits); mask++) {
            if (dp[mask] == -1) continue;
            int idx = __builtin_popcount(mask);
            if (idx >= n) { best = max(best, dp[mask]); continue; }
            for (int p = 0; p < bits; p++) {
                if (mask & (1 << p)) continue;
                int slot = p / 2 + 1;
                int val = nums[idx] & slot;
                int nm = mask | (1 << p);
                dp[nm] = max(dp[nm], dp[mask] + val);
            }
            best = max(best, dp[mask]);
        }
        return best;
    }
};
