// Link: https://leetcode.com/problems/build-array-from-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = 0; i < (int)nums.size(); i++) res[i] = nums[nums[i]];
        return res;
    }
};
