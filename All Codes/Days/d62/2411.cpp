// Link: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 32) amortized (each earlier index j only gets extended while
//     new bits keep appearing, so total work across all i is bounded by
//     n * bit-width)
// SC: O(1) extra (mutates nums in place to track running OR per position)
// Approach: process left to right; nums[j] is repurposed to hold the OR of
// the original nums[j..i] as i advances. For each new index i with value
// x, walk backward from i-1 extending every earlier j whose accumulated OR
// doesn't already include all of x's bits (ORing x in and updating
// res[j]'s window length), stopping as soon as a j's OR already contains x
// entirely (its window is already big enough to capture every bit x has,
// so extending it further can't shrink its answer).
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 0; i < len; ++i) {
            int x = nums[i];
            res[i] = 1;
            int j = i - 1;
            while (j >= 0 && (nums[j] | x) != nums[j]) {
                res[j] = i - j + 1;
                nums[j] |= x;
                --j;
            }
        }
        return res;
    }
};
