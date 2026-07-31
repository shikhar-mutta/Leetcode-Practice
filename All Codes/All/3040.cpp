// Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) per starting choice (3 memoized interval DPs), SC: O(n^2)
// Approach: Try each of the 3 possible pair-sum targets fixed by the first
// two ops (front pair, back pair, first+last), then interval-DP over the
// remaining range: at each (l,r), try consuming (l,l+1), (r-1,r), or (l,r)
// if its sum matches target, recursing into the shrunk interval.
class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int target, int l,
              int r) {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int num = 0, num1 = 0, num2 = 0;
        if ((l + 1) <= r && (nums[l] + nums[l + 1]) == target)
            num = 1 + solve(dp, nums, target, l + 2, r);
        if ((r - 1) >= l && (nums[r] + nums[r - 1]) == target)
            num1 = 1 + solve(dp, nums, target, l, r - 2);
        if ((nums[l] + nums[r]) == target)
            num2 = 1 + solve(dp, nums, target, l + 1, r - 1);
        return dp[l][r] = max(num, max(num1, num2));
    }
    int maxOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int num = 1 + solve(dp, nums, nums[0] + nums[1], 2, nums.size() - 1);
        dp.resize(nums.size(), vector<int>(nums.size(), -1));
        int num1 =
            1 + solve(dp, nums, nums[nums.size() - 1] + nums[nums.size() - 2],
                      0, nums.size() - 3);
        dp.resize(nums.size(), vector<int>(nums.size(), -1));
        int num2 = 1 + solve(dp, nums, nums[0] + nums[nums.size() - 1], 1,
                             nums.size() - 2);
        return max(num, max(num1, num2));
    }
};
