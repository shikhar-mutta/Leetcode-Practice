// Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(queries * n / step) SC: O(1)
// Approach: direct simulation. Each query [l, r, step, val] multiplies
// nums[l], nums[l+step], ... (while <= r) by val mod 1e9+7, in order.
// After all queries, XOR every element together.
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        for (auto& q : queries) {
            int l = q[0], r = q[1], step = q[2], val = q[3];
            for (int i = l; i <= r; i += step) {
                nums[i] = (int)((long long)nums[i] * val % MOD);
            }
        }
        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }
};
