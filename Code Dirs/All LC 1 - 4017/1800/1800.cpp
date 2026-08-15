// Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i-1]) cur += nums[i];
            else cur = nums[i];
            best = max(best, cur);
        }
        return best;
    }
};
