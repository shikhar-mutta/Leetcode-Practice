// Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int groups = 1;
        int groupBase = nums[0];
        for (int x : nums) {
            if (x - groupBase > k) {
                groups++;
                groupBase = x;
            }
        }
        return groups;
    }
};
