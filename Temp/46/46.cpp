// Link: https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n! * n)  SC: O(n) recursion depth (excluding output)
// Approach: backtracking with a used[] array, iterating nums in original order at each level
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> cur;
        vector<vector<int>> res;
        function<void()> bt = [&]() {
            if ((int)cur.size() == n) { res.push_back(cur); return; }
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                used[i] = true;
                cur.push_back(nums[i]);
                bt();
                cur.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};
