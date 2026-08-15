// Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(n)
    // Approach:
    //   1. We can use dynamic programming to solve this problem. We can create a dp array of size n to store the maximum points we can get for each column in the current row. We can iterate through each row and update the dp array by adding the points in the current row and subtracting the cost of moving to the next column. We can use two passes to update the dp array, one from left to right and one from right to left. Finally, we can return the maximum value in the dp array after processing all rows.
    long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();
        vector<long> dp(n, 0);
        long ans = 0;

        for (int i = 0; i < m; ++i)
        {

            for (int j = 0; j < n; ++j)
            {
                dp[j] += points[i][j];
            }

            for (int j = 1; j < n; ++j)
            {
                dp[j] = max(dp[j], dp[j - 1] - 1);
            }

            for (int j = n - 2; j >= 0; --j)
            {
                dp[j] = max(dp[j], dp[j + 1] - 1);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
