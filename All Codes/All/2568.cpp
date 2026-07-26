// Link: https://leetcode.com/problems/minimum-impossible-or/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: any subset OR-sum reachable is exactly the OR of a subset of
// the powers of 2 present in nums (since OR-ing non-power-of-2 numbers
// never produces a "new" bit combination that a subset of individual
// present bits couldn't already reach). So track which powers of 2
// (2^0..2^30) actually appear in nums, and the answer is the smallest
// power of 2 that's missing.
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int frec[32]{0};
        for (int x : nums) {
            if (__builtin_popcount(x) == 1) {
                frec[31 - __builtin_clz(x)]++;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (!frec[i])
                return 1 << i;
        }
        return -1;
    }
};
