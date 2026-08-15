// Link: https://leetcode.com/problems/combination-sum-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(C(9,k))  SC: O(k) recursion depth (excluding output)
// Approach: backtracking picking distinct digits 1-9 in increasing order, pruning when sum exceeds n
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> bt = [&](int start, int remain) {
            if ((int)cur.size() == k) { if (remain == 0) res.push_back(cur); return; }
            for (int i = start; i <= 9; i++) {
                if (i > remain) break;
                cur.push_back(i);
                bt(i + 1, remain - i);
                cur.pop_back();
            }
        };
        bt(1, n);
        return res;
    }
};
