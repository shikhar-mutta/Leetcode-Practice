// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two-pointer in-place: write index k advances only when a new distinct value is found
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (k == 0 || nums[i] != nums[k-1]) nums[k++] = nums[i];
        }
        return k;
    }
};
