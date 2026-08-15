// Link: https://leetcode.com/problems/non-decreasing-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: scan for descents; allow at most one modification. Prefer lowering nums[i] to nums[i-1] when possible, otherwise raise nums[i-1] to nums[i].
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int mods = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] > nums[i]) {
                mods++;
                if (mods > 1) return false;
                if (i-2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
