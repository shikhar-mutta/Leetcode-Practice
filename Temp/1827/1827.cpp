// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                ops += nums[i-1] + 1 - nums[i];
                nums[i] = nums[i-1] + 1;
            }
        }
        return ops;
    }
};
