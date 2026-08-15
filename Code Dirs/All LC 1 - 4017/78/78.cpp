// Link: https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(1) extra (excluding output)
// Approach: iterate all bitmasks 0..2^n-1, bit i set means include nums[i] (binary-counting subset order)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> cur;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) cur.push_back(nums[i]);
            res.push_back(cur);
        }
        return res;
    }
};
