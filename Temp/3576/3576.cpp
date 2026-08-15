// Link: https://leetcode.com/problems/transform-array-to-all-equal-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: the operation flips a pair, so its net effect propagates
// like a running sign flag: scan left to right applying an accumulated
// sign, and whenever the current (signed) element doesn't match the
// target, that's a forced operation at this position, flipping the sign
// for everything after it. Try both possible targets (nums[0] or its
// negation) and check the total flips needed is <= k and the sign chain
// ends up consistent at the last element.
class Solution {
    bool check(vector<int>& nums, int target, int k) {
        int cnt = 0, sign = 1;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            int x = nums[i] * sign;
            if (x == target) sign = 1;
            else { sign = -1; cnt++; }
        }
        return cnt <= k && nums.back() * sign == target;
    }
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, nums[0], k) || check(nums, -nums[0], k);
    }
};
