// Link: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIncreasing(vector<int>& nums, int skip) {
        int prev = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i == skip) continue;
            if (nums[i] <= prev) return false;
            prev = nums[i];
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isIncreasing(nums, i)) return true;
        }
        return false;
    }
};
