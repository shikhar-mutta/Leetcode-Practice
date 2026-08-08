// Link: https://leetcode.com/problems/find-pivot-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: total sum first; track running left sum, compare to (total - left - nums[i]) for right sum.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (leftSum == total - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
