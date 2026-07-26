// Link: https://leetcode.com/problems/longest-nice-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: a subarray is "nice" iff its elements are pairwise bitwise-AND
// zero, which (since AND-zero is transitive across a whole set here) is
// equivalent to no bit position being set in more than one element - i.e.
// the OR of all elements has no repeated bit. Sliding window: maintain
// `mask` = OR of the current window; if adding nums[right] would conflict
// with an existing bit in mask, shrink from the left (removing bits via
// XOR, valid since each bit in mask is currently set by exactly one
// window element) until the conflict clears, then extend the window.
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, mask = 0, res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (mask & nums[right]) { // bit conflict: shrink window
                mask ^= nums[left];      // remove left element's bits
                ++left;
            }
            mask |= nums[right]; // add current element's bits
            res = max(res, right - left + 1);
        }
        return res;
    }
};
