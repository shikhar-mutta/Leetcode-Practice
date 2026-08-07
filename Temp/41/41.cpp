// Link: https://leetcode.com/problems/first-missing-positive/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: cyclic placement — swap each value v in [1,n] to index v-1, then scan for the first index mismatch
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
