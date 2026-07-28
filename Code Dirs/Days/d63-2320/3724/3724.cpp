// Link: https://leetcode.com/problems/minimum-operations-to-transform-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: since append only adds to the end and never reorders, the
// final array is exactly nums1's n elements (adjusted) followed by one
// appended duplicate. Base cost = sum |nums1[j]-nums2[j]| for the first
// n positions (fixed regardless of choice), plus 1 for the append. The
// duplicated index i can be appended at any value along its own
// adjustment path from nums1[i] to nums2[i] "for free" (that path's
// cost is already counted in the base sum), so choosing the append
// value as close as possible to nums2[n] costs extra only if nums2[n]
// falls outside [min(nums1[i],nums2[i]), max(nums1[i],nums2[i])] — pick
// the index i minimizing that extra distance.
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long base = 0;
        for (int j = 0; j < n; j++) base += llabs((long long)nums1[j] - nums2[j]);

        long long target = nums2[n];
        long long minExtra = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long lo = min(nums1[i], nums2[i]), hi = max(nums1[i], nums2[i]);
            long long extra = max({0LL, lo - target, target - hi});
            minExtra = min(minExtra, extra);
        }
        return base + 1 + minExtra;
    }
};
