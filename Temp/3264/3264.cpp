// Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int op = 0; op < k; op++) {
            int idx = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[idx]) idx = i;
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};
