// Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sum/2)  SC: O(sum/2)
// Approach: 0/1 knapsack - can we reach sum/2 using a subset of nums?
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int t = target; t >= x; t--) {
                dp[t] = dp[t] || dp[t - x];
            }
        }
        return dp[target];
    }
};
