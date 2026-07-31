// Link: https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: dp[j] stores the minimum cost if nums[j] is the element left behind.
// We step forward by 2, processing nums[i] and nums[i+1]. For each pair, we evaluate all possible elements (nums[j]) that could have been carried over and update dp[j] accordingly. Finally, we handle the last element(s) based on whether n is odd or even, and return the minimum cost.
class Solution
{
public:
    int minCost(vector<int> &nums)
    {
        int n = nums.size();

        // Base cases for very small arrays
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // dp[j] stores the minimum cost if nums[j] is the element left behind.
        vector<int> dp(n, 0);

        // We step forward by 2, processing nums[i] and nums[i+1]
        int i = 1;
        for (; i < n - 1; i += 2)
        {
            int cost_leave_i = INT_MAX;
            int cost_leave_i_plus_1 = INT_MAX;

            // Evaluate all possible elements (nums[j]) that could have been carried over
            for (int j = 0; j < i; j++)
            {
                // Option 1: Leave nums[i] behind, remove nums[j] and nums[i+1]
                cost_leave_i = min(cost_leave_i, dp[j] + max(nums[j], nums[i + 1]));

                // Option 2: Leave nums[i+1] behind, remove nums[j] and nums[i]
                cost_leave_i_plus_1 = min(cost_leave_i_plus_1, dp[j] + max(nums[j], nums[i]));

                // Option 3: Leave nums[j] behind, remove nums[i] and nums[i+1]
                // We can safely update dp[j] in-place because we already used its
                // old value to calculate the two variables above.
                dp[j] += max(nums[i], nums[i + 1]);
            }

            // Append the new carry states for the current pair
            dp[i] = cost_leave_i;
            dp[i + 1] = cost_leave_i_plus_1;
        }

        int ans = INT_MAX;

        // If n is odd, the loop stops with exactly one element remaining (the carry).
        // We must remove it in a single operation.
        if (i == n)
        {
            for (int j = 0; j < n; j++)
            {
                ans = min(ans, dp[j] + nums[j]);
            }
        }
        // If n is even, the loop stops with the carry AND the final element remaining.
        // We remove them both.
        else
        {
            for (int j = 0; j < n - 1; j++)
            {
                ans = min(ans, dp[j] + max(nums[j], nums[n - 1]));
            }
        }

        return ans;
    }
};