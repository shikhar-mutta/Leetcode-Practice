// Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 2; i <= n; i++) {
            if (nums[i-1] == nums[i-2] && dp[i-2]) dp[i] = true;
            if (i >= 3 && nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3] && dp[i-3]) dp[i] = true;
            if (i >= 3 && nums[i-1] == nums[i-2] + 1 && nums[i-2] == nums[i-3] + 1 && dp[i-3]) dp[i] = true;
        }
        return dp[n];
    }
};
