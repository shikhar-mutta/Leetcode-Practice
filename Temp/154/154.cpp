// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) avg, O(n) worst (dup-heavy)  SC: O(1)
// Approach: binary search comparing nums[mid] vs nums[r]; when equal, can't tell which half is sorted
// so shrink r by 1 (safe since r itself is a duplicate of the compared value)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};
