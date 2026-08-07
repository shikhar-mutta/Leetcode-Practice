// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(n,m)))  SC: O(1)
// Approach: binary search the partition point on the smaller array so that
// left halves combined equal right halves combined (size-balanced), with
// max(left) <= min(right) on both sides; median derived from those 4 borders.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();
        int lo = 0, hi = n;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = (n + m + 1) / 2 - i;
            int leftA = (i == 0) ? INT_MIN : nums1[i-1];
            int rightA = (i == n) ? INT_MAX : nums1[i];
            int leftB = (j == 0) ? INT_MIN : nums2[j-1];
            int rightB = (j == m) ? INT_MAX : nums2[j];
            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2 == 0)
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                return max(leftA, leftB);
            } else if (leftA > rightB) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};
