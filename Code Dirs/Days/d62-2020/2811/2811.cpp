// Link: https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: any split eventually reduces to repeatedly peeling off single
// elements once a subarray's length reaches 2 (the only requirement being
// each split piece has length 1 or sum >= m). This is achievable overall iff
// n <= 2 (trivially splittable) or SOME pair of original adjacent elements
// sums to >= m — that pair can be isolated first (splitting everything else
// off around it one element at a time), after which the rest reduces to
// single elements freely.
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2)
            return true;

        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] + nums[i + 1] >= m)
                return true;
        }
        return false;
    }
};
