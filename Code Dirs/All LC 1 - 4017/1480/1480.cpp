// Link: https://leetcode.com/problems/running-sum-of-1d-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) nums[i] += nums[i-1];
        return nums;
    }
};
