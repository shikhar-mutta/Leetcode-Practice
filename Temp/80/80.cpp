// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: write index k, admit nums[i] if k<2 or it differs from nums[k-2] (allows up to 2 of each value)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (k < 2 || nums[i] != nums[k-2]) nums[k++] = nums[i];
        }
        return k;
    }
};
