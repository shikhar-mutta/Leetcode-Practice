// Link: https://leetcode.com/problems/special-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0); // prefix[i] = number of "bad" adjacent pairs in [0..i]
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + (nums[i] % 2 == nums[i-1] % 2 ? 1 : 0);
        }
        vector<bool> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            bool ok = (l == r) || (prefix[r] - prefix[l] == 0);
            res.push_back(ok);
        }
        return res;
    }
};
