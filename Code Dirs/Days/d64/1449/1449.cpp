// Link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(target * 9) SC: O(target)
// Approach: Use dynamic programming to find the largest integer that can be formed with digits that add up to the target. We can use a 1D dp array where dp[t] represents the maximum number of digits that can be formed with a total cost of t. We iterate through each digit and update the dp array accordingly. Finally, we construct the largest integer by backtracking through the dp array.
class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int t = 1; t <= target; t++)
        {
            for (int d = 0; d < 9; d++)
            {
                if (cost[d] <= t && dp[t - cost[d]] != INT_MIN)
                    dp[t] = max(dp[t], dp[t - cost[d]] + 1);
            }
        }
        if (dp[target] <= 0)
            return "0";
        string res;
        int t = target;
        while (t > 0)
        {
            for (int d = 8; d >= 0; d--)
            {
                if (cost[d] <= t && dp[t - cost[d]] == dp[t] - 1)
                {
                    res += char('1' + d);
                    t -= cost[d];
                    break;
                }
            }
        }
        return res;
    }
};
