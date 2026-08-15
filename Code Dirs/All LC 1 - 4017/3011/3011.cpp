// Link: https://leetcode.com/problems/find-if-array-can-be-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevMax = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            int pc = __builtin_popcount(nums[i]);
            int lo = nums[i], hi = nums[i];
            while (j < n && __builtin_popcount(nums[j]) == pc) {
                lo = min(lo, nums[j]);
                hi = max(hi, nums[j]);
                j++;
            }
            if (lo < prevMax) return false;
            prevMax = hi;
            i = j;
        }
        return true;
    }
};
