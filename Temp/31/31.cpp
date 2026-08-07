// Link: https://leetcode.com/problems/next-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: find rightmost ascent nums[i]<nums[i+1], swap with smallest greater element to its right, then reverse the suffix
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
