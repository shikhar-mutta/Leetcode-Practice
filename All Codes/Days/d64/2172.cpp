// Link: https://leetcode.com/problems/maximum-and-sum-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(3^numSlots * numSlots)  SC: O(3^numSlots)
// Approach: base-3 bitmask DP over slot fill counts (each slot capacity 2,
// digit 0/1/2 free slots remaining... here digit = number of nums already
// placed in that slot, 0..2). dp[mask] = max AND-sum achievable using the
// first popcount(mask) nums, with slot fill state encoded by mask. For
// each mask, next num index = total filled so far; try placing it in any
// slot with remaining capacity by incrementing that digit.
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        vector<int> pow3(numSlots + 1);
        pow3[0] = 1;
        for (int i = 1; i <= numSlots; i++) pow3[i] = pow3[i-1] * 3;
        int total = pow3[numSlots];
        vector<int> dp(total, -1);
        dp[0] = 0;
        int best = 0;
        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] < 0) continue;
            int filled = 0, m = mask;
            for (int s = 0; s < numSlots; s++) { filled += m % 3; m /= 3; }
            if (filled >= n) { best = max(best, dp[mask]); continue; }
            int val = nums[filled];
            int m2 = mask;
            for (int s = 0; s < numSlots; s++) {
                int digit = (mask / pow3[s]) % 3;
                if (digit < 2) {
                    int nmask = mask + pow3[s];
                    int cand = dp[mask] + (val & (s + 1));
                    if (cand > dp[nmask]) dp[nmask] = cand;
                }
            }
        }
        for (int mask = 0; mask < total; mask++) best = max(best, dp[mask]);
        return best;
    }
};
