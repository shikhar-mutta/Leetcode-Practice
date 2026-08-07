// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) avg, O(n) worst (dup-heavy)  SC: O(1)
// Approach: modified binary search; when nums[l]==nums[mid]==nums[r] can't tell which half is sorted, shrink both ends
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) { l++; r--; }
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
