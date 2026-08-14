// Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        for (int i = 0; i < n; i++) {
            auto loIt = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto hiIt = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += hiIt - loIt;
        }
        return count;
    }
};
