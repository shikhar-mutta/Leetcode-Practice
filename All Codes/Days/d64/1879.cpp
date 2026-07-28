// Link: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^n * n)  SC: O(2^n)
// Approach: assignment-problem bitmask DP. dp[mask] = min xor sum pairing
// nums1[0..popcount(mask)-1] with the nums2 indices marked in mask.
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int full = 1 << n;
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            int i = __builtin_popcount(mask);
            if (i >= n) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                int nmask = mask | (1 << j);
                int val = dp[mask] + (nums1[i] ^ nums2[j]);
                dp[nmask] = min(dp[nmask], val);
            }
        }
        return dp[full - 1];
    }
};
