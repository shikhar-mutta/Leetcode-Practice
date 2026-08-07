// Link: https://leetcode.com/problems/non-decreasing-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n)  SC: O(n) recursion
// Approach: backtrack building non-decreasing subsequences, using a set at
// each recursion level to skip duplicate values (avoids duplicate subsequences)
class Solution {
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int start, vector<int>& cur) {
        if (cur.size() >= 2) res.push_back(cur);
        unordered_set<int> used;
        for (int i = start; i < (int)nums.size(); i++) {
            if (!cur.empty() && nums[i] < cur.back()) continue;
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums, 0, cur);
        return res;
    }
};
