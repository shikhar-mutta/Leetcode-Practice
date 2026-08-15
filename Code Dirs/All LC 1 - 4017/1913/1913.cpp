// Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};
