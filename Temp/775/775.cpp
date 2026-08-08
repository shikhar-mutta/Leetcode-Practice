// Link: https://leetcode.com/problems/global-and-local-inversions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: global inversions == local inversions iff every element is at most 1 away from its index (any further displacement creates a non-adjacent inversion).
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (abs(nums[i] - i) > 1) return false;
        }
        return true;
    }
};
