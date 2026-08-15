// Link: https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);

        int i = 1;
        for (; i < n - 1; i += 2) {
            int cost_leave_i = INT_MAX;
            int cost_leave_i_plus_1 = INT_MAX;

            for (int j = 0; j < i; j++) {
                cost_leave_i = min(cost_leave_i, dp[j] + max(nums[j], nums[i + 1]));
                cost_leave_i_plus_1 = min(cost_leave_i_plus_1, dp[j] + max(nums[j], nums[i]));
                dp[j] += max(nums[i], nums[i + 1]);
            }

            dp[i] = cost_leave_i;
            dp[i + 1] = cost_leave_i_plus_1;
        }

        int ans = INT_MAX;

        if (i == n) {
            for (int j = 0; j < n; j++) {
                ans = min(ans, dp[j] + nums[j]);
            }
        } else {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans, dp[j] + max(nums[j], nums[n - 1]));
            }
        }

        return ans;
    }
};
