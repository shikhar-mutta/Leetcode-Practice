// Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, best = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) inc++; else inc = 1;
            if (nums[i] < nums[i-1]) dec++; else dec = 1;
            best = max({best, inc, dec});
        }
        return best;
    }
};
