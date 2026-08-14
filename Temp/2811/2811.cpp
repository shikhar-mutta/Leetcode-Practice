// Link: https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        for (int i = 0; i + 1 < n; i++)
            if (nums[i] + nums[i+1] >= m) return true;
        return false;
    }
};
