// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: lower_bound for the first occurrence, upper_bound-1 for the last
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        if (lo == nums.end() || *lo != target) return {-1, -1};
        auto hi = upper_bound(nums.begin(), nums.end(), target);
        return {(int)(lo - nums.begin()), (int)(hi - nums.begin()) - 1};
    }
};
