// Link: https://leetcode.com/problems/maximum-score-from-grid-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: We can use dynamic programming to solve this problem. We will maintain a dp array where dp[h][0] represents the maximum score we can achieve by ending at height h without any operation, dp[h][1] represents the maximum score we can achieve by ending at height h with an increment operation, and dp[h][2] represents the maximum score we can achieve by ending at height h with a decrement operation. We will iterate through each column of the grid and update the dp array based on the previous column's values. Finally, we will return the maximum value from the dp array as the answer.
class Solution
{
public:
    long long maximumScore(vector<vector<int>> &grid)
    {
        int n = grid.size();

        long long pref[(n + 1) * n];
        for (int j = 0; j < n; ++j)
        {
            pref[0 * n + j] = 0;
            for (int i = 0; i < n; ++i)
            {
                pref[(i + 1) * n + j] = pref[i * n + j] + grid[i][j];
            }
        }
        long long dp[101][3];
        long long next_dp[101][3];
        for (int h = 0; h <= n; ++h)
        {
            dp[h][0] = 0;
            dp[h][1] = -1e18;
            dp[h][2] = -1e18;
        }

        for (int j = 0; j < n; ++j)
        {
            long long max_prev = -1e18;
            for (int h = 0; h <= n; ++h)
            {
                long long m = dp[h][0];
                if (dp[h][1] > m)
                    m = dp[h][1];
                if (dp[h][2] > m)
                    m = dp[h][2];
                if (m > max_prev)
                    max_prev = m;
            }
            long long running_max_inc = -1e18;
            for (int h = 0; h <= n; ++h)
            {
                next_dp[h][2] = max_prev;
                if (j > 0)
                {
                    long long prev_val =
                        (dp[h][0] > dp[h][2]) ? dp[h][0] : dp[h][2];
                    long long current_inc = prev_val - pref[h * n + (j - 1)];
                    if (current_inc > running_max_inc)
                        running_max_inc = current_inc;
                    next_dp[h][0] = running_max_inc + pref[h * n + (j - 1)];
                }
                else
                {
                    next_dp[h][0] = 0;
                }
            }
            long long running_max_dec = -1e18;
            if (j > 0)
            {
                for (int h = n; h >= 0; --h)
                {
                    long long m = dp[h][0];
                    if (dp[h][1] > m)
                        m = dp[h][1];
                    if (dp[h][2] > m)
                        m = dp[h][2];
                    long long current_h_best = m + pref[h * n + j];
                    if (current_h_best > running_max_dec)
                        running_max_dec = current_h_best;
                    next_dp[h][1] = running_max_dec - pref[h * n + j];
                }
            }
            else
            {
                for (int h = 0; h <= n; ++h)
                    next_dp[h][1] = -1e18;
            }

            for (int h = 0; h <= n; ++h)
            {
                dp[h][0] = next_dp[h][0];
                dp[h][1] = next_dp[h][1];
                dp[h][2] = next_dp[h][2];
            }
        }

        long long ans = 0;
        for (int h = 0; h <= n; ++h)
        {
            if (dp[h][0] > ans)
                ans = dp[h][0];
            if (dp[h][1] > ans)
                ans = dp[h][1];
            if (dp[h][2] > ans)
                ans = dp[h][2];
        }
        return ans;
    }
};
