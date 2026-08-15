// Link: https://leetcode.com/problems/random-pick-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) pick  SC: O(n)
// Approach: reservoir sampling over matching indices - avoids extra memory
// for value->indices map (or could precompute a map for O(1) construction
// tradeoff); here we scan and reservoir-sample matches each call
class Solution {
    vector<int> nums;

public:
    Solution(vector<int>& nums) : nums(nums) {}

    int pick(int target) {
        int result = -1, count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                count++;
                if (rand() % count == 0) result = i;
            }
        }
        return result;
    }
};
