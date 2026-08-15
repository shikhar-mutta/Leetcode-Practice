// Link: https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(n) recursion depth (excluding output)
// Approach: sort, backtrack recording every subset; skip a duplicate value at the same recursion level to avoid dup subsets
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> bt = [&](int start) {
            res.push_back(cur);
            for (int i = start; i < (int)nums.size(); i++) {
                if (i > start && nums[i] == nums[i-1]) continue;
                cur.push_back(nums[i]);
                bt(i + 1);
                cur.pop_back();
            }
        };
        bt(0);
        return res;
    }
};
