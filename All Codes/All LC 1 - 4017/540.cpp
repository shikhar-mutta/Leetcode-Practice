// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary search on even indices; if nums[mid]==nums[mid+1], the
// single element is after mid, else at or before mid
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) lo = mid + 2;
            else hi = mid;
        }
        return nums[lo];
    }
};
