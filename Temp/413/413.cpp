// Link: https://leetcode.com/problems/arithmetic-slices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track running arithmetic run length; each extension of a run
// by 1 adds (run-1) new slices ending here
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0, cur = 0;
        for (int i = 2; i < (int)nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                cur++;
                total += cur;
            } else {
                cur = 0;
            }
        }
        return total;
    }
};
