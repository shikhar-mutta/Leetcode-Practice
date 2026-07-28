// Link: https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(n)
//  Approach: Use a 1D DP array to optimize space complexity. For each row, update the DP array based on the minimum cost to reach each column, considering the alternating directions and wait costs.
// The DP transition is as follows:
// dp[j] = min(dp[j - 1] + waitCost[i][j - 1], dp[j] + waitCost[i - 1][j]) + (i + 1) * (j + 1);
// The final answer is the value in dp[n - 1] after processing all rows.
class Solution
{
public:
    long long minCost(int m, int n, vector<vector<int>> &waitCost)
    {
        vector<long long> dp(n);
        dp[0] = 1;
        waitCost[0][0] = 0;
        for (int j = 1; j < n; ++j)
            dp[j] = dp[j - 1] + waitCost[0][j - 1] + (j + 1);
        for (int i = 1; i < m; ++i)
        {
            dp[0] += waitCost[i - 1][0] + (i + 1);
            for (int j = 1; j < n; ++j)
            {
                dp[j] = min(dp[j - 1] + waitCost[i][j - 1], dp[j] + waitCost[i - 1][j]) + (i + 1) * (j + 1);
            }
        }
        return dp[n - 1];
    }
};