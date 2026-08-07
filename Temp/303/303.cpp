// Link: https://leetcode.com/problems/range-sum-query-immutable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) construct, O(1) sumRange  SC: O(n)
// Approach: prefix sum array, sumRange = prefix[right+1] - prefix[left]
class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
