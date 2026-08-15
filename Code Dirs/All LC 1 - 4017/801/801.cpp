// Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: DP tracking min swaps to make both sequences strictly increasing up to index i, in two states: keep[i] (no swap at i) and swap[i] (swapped at i). Transition based on whether the "no-swap" or "swap" configuration maintains increasing order with the previous index.
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int keep = 0, swp = 1;
        for (int i = 1; i < n; i++) {
            int nKeep = INT_MAX, nSwap = INT_MAX;
            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                nKeep = min(nKeep, keep);
                nSwap = min(nSwap, swp + 1);
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                nKeep = min(nKeep, swp);
                nSwap = min(nSwap, keep + 1);
            }
            keep = nKeep;
            swp = nSwap;
        }
        return min(keep, swp);
    }
};
