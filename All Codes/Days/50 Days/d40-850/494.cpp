// Link: https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * s), SC: O(s), where n = nums.size(), s = (total + target) / 2
// Approach: DP, 1D array
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // Let P = sum of '+' elements, N = sum of '-' elements.
        // P - N = target and P + N = total  =>  P = (total + target) / 2.
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + target) % 2 != 0)
            return 0;

        int s = (total + target) / 2;
        vector<int> dp(s + 1, 0); // dp[j] = #subsets with sum j
        dp[0] = 1;
        for (int x : nums)
            for (int j = s; j >= x; j--)
                dp[j] += dp[j - x];
        return dp[s];
    }
};
