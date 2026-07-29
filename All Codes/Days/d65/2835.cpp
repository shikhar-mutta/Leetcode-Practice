// Link: https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxBit), SC: O(maxBit)
// Approach: nums are all powers of 2, so bucket by exponent. Walk target's bits from low to
// high, keeping a "have" count of available pieces at the current level (merging surplus pairs
// upward, like binary carry, is free). Whenever a bit is needed but have==0, borrow from the
// nearest higher nonempty bucket, splitting it down one level at a time (each split = 1 op).
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long total = 0;
        for (int x : nums) total += x;
        if (total < target) return -1;

        int maxBit = 32;
        vector<long long> cnt(maxBit + 2, 0);
        for (int x : nums) cnt[__builtin_ctz((unsigned)x)]++;

        long long ops = 0, have = 0;
        for (int i = 0; i <= maxBit; i++) {
            have += cnt[i];
            int bit = (i < 32) ? ((target >> i) & 1) : 0;
            if (bit) {
                if (have == 0) {
                    int j = i + 1;
                    while (j <= maxBit + 1 && cnt[j] == 0) j++;
                    ops += j - i;
                    cnt[j]--;
                    have = 1;
                }
                have--;
            }
            have /= 2;
        }
        return (int)ops;
    }
};
