// Link: https://leetcode.com/problems/combination-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: exponential  SC: O(n) recursion depth (excluding output)
// Approach: sort, backtrack with a start index, skip duplicate values at the same recursion level to avoid duplicate combos
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> bt = [&](int start, int remain) {
            if (remain == 0) { res.push_back(cur); return; }
            for (int i = start; i < (int)candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                if (candidates[i] > remain) break;
                cur.push_back(candidates[i]);
                bt(i + 1, remain - candidates[i]);
                cur.pop_back();
            }
        };
        bt(0, target);
        return res;
    }
};
