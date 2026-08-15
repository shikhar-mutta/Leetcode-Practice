// Link: https://leetcode.com/problems/remove-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two-pointer in-place: write index k advances only for values != val
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};
