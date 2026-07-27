// Link: https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) SC: O(n)
// Approach: a split into two subsets both with product == target is only
// possible if the total product equals target^2 (checked upfront). Given
// that, n is small, so backtrack over include/exclude for each element,
// tracking the running product of the "included" subset (pruning once it
// exceeds target) until some non-empty proper subset hits target exactly
// — its complement then automatically also equals target.
class Solution {
    bool found = false;
    int n;
    void dfs(vector<int>& nums, long long target, int idx, long long prod, int count) {
        if (found || prod > target) return;
        if (idx == n) {
            if (prod == target && count > 0 && count < n) found = true;
            return;
        }
        dfs(nums, target, idx + 1, prod, count);
        if (found) return;
        dfs(nums, target, idx + 1, prod * nums[idx], count + 1);
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        long long total = 1;
        for (int x : nums) total *= x;
        if (total != target * target) return false;
        dfs(nums, target, 0, 1, 0);
        return found;
    }
};
