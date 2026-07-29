// Link: https://leetcode.com/problems/paint-house-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * target) SC: O(n * target)
// Approach: We can use dynamic programming to solve this problem. We can use a 2D dp array where dp[i][j] represents the minimum cost to paint the first i houses with j neighborhoods. We iterate through each house and each color and update the dp array accordingly. Finally, we return the minimum cost to paint all houses with exactly target neighborhoods.
class Solution
{
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
                int target)
    {
        const int INF = 1e9;
        // 1. Declare permanent 2D structures once
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));
        vector<vector<int>> next_dp(n + 1, vector<int>(target + 1, INF));
        dp[0][0] = 0; // Virtual starter state
        int min_total_cost = INF;
        // 2. Use fixed-size flat arrays for your snapshot buffers instead of
        // dynamic vectors Sized safely to 101 to easily accommodate target
        // limits up to 100 + 1
        int min1_cost[101];
        int min1_color[101];
        int min2_cost[101];
        for (int i = 0; i < m; ++i)
        {
            // Reset next_dp buffer to INF without re-allocating memory
            for (int j = 0; j <= n; ++j)
            {
                fill_n(next_dp[j].begin(), target + 1, INF);
            }
            // Reset our snapshot arrays for the current house pass
            fill_n(min1_cost, target + 1, INF);
            fill_n(min1_color, target + 1, -1);
            fill_n(min2_cost, target + 1, INF);
            // Step 1: Populate snapshots from the previous row
            for (int hoods = 0; hoods <= target; ++hoods)
            {
                for (int color = 0; color <= n; ++color)
                {
                    if (i > 0 && color == 0)
                        continue;
                    int current_cost = dp[color][hoods];
                    if (current_cost < min1_cost[hoods])
                    {
                        min2_cost[hoods] = min1_cost[hoods];
                        min1_cost[hoods] = current_cost;
                        min1_color[hoods] = color;
                    }
                    else if (current_cost < min2_cost[hoods])
                    {
                        min2_cost[hoods] = current_cost;
                    }
                }
            }
            // Step 2: Evaluate current house
            if (houses[i] != 0)
            {
                int c = houses[i];
                for (int hoods = 0; hoods <= target; ++hoods)
                {
                    if (dp[c][hoods] != INF)
                    {
                        next_dp[c][hoods] =
                            min(next_dp[c][hoods], dp[c][hoods]);
                    }
                    if (hoods + 1 <= target)
                    {
                        int best_prev = (c == min1_color[hoods])
                                            ? min2_cost[hoods]
                                            : min1_cost[hoods];
                        if (best_prev != INF)
                        {
                            next_dp[c][hoods + 1] =
                                min(next_dp[c][hoods + 1], best_prev);
                        }
                    }
                    if (i == m - 1)
                    {
                        min_total_cost =
                            min(min_total_cost, next_dp[c][target]);
                    }
                }
            }
            else
            {
                for (int hoods = 0; hoods <= target; ++hoods)
                {
                    for (int c = 1; c <= n; ++c)
                    {
                        if (dp[c][hoods] != INF)
                        {
                            next_dp[c][hoods] =
                                min(next_dp[c][hoods],
                                    dp[c][hoods] + cost[i][c - 1]);
                        }
                        if (hoods + 1 <= target)
                        {
                            int best_prev = (c == min1_color[hoods])
                                                ? min2_cost[hoods]
                                                : min1_cost[hoods];
                            if (best_prev != INF)
                            {
                                next_dp[c][hoods + 1] =
                                    min(next_dp[c][hoods + 1],
                                        best_prev + cost[i][c - 1]);
                            }
                        }
                        if (i == m - 1 &&
                            (hoods == target || hoods + 1 == target))
                        {
                            min_total_cost =
                                min(min_total_cost, next_dp[c][target]);
                        }
                    }
                }
            }
            // Swap matrix buffers without allocation overhead
            dp.swap(next_dp);
        }
        return (min_total_cost >= INF) ? -1 : min_total_cost;
    }
};