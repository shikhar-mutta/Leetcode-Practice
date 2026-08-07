// Link: https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: exponential  SC: O(target) recursion depth (excluding output)
// Approach: backtracking with a start index (allowing repeats of the same candidate), prune when running sum exceeds target
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> bt = [&](int start, int remain) {
            if (remain == 0) { res.push_back(cur); return; }
            for (int i = start; i < (int)candidates.size(); i++) {
                if (candidates[i] > remain) continue;
                cur.push_back(candidates[i]);
                bt(i, remain - candidates[i]);
                cur.pop_back();
            }
        };
        bt(0, target);
        return res;
    }
};
