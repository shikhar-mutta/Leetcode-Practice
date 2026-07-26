// Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the maximum possible bitwise AND of any subarray is just the
// maximum single element (ANDing in any smaller value can only decrease
// or preserve it, never increase it), so the answer is the longest run of
// consecutive elements all equal to that maximum value.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        int best = 0, cur = 0;
        for (int x : nums) {
            if (x == maxVal) {
                best = std::max(best, ++cur);
            } else {
                cur = 0;
            }
        }
        return best;
    }
};
