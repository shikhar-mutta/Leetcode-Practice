// Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ops = 0, level = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) level++;
            ops += level;
        }
        return ops;
    }
};
