// Link: https://leetcode.com/problems/combination-sum-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(target * nums.size())  SC: O(target)
// Approach: dp[t] = number of ordered combinations summing to t;
// dp[t] = sum of dp[t-n] over each num n
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (int n : nums) {
                if (n <= t) dp[t] += dp[t - n];
            }
        }
        return (int)dp[target];
    }
};
