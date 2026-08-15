// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary search comparing nums[mid] vs nums[r]; if mid>r, min is in the right half, else min could be mid itself
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
