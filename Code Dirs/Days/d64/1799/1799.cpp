// Link: https://leetcode.com/problems/maximize-score-after-n-operations/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^n * n^2)  SC: O(2^n)
// Approach: bitmask DP over which elements are used. dp[mask] = max score
// using popcount(mask)/2 completed operations on the chosen indices.
// For each mask, pick a pair of unused indices to form the next operation.
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int full = 1 << n;
        vector<int> dp(full, 0);
        for (int mask = 0; mask < full; mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2 != 0) continue;
            int op = cnt / 2 + 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                for (int j = i + 1; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nmask = mask | (1 << i) | (1 << j);
                    int val = op * __gcd(nums[i], nums[j]) + dp[mask];
                    dp[nmask] = max(dp[nmask], val);
                }
            }
        }
        return dp[full - 1];
    }
};
