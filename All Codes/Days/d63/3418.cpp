// Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(h * w) SC: O(w)
//  Approach: DP over dp[x][k] = max money reaching column x using k of the
//  (at most 2) available "neutralize a negative cell to 0" powers. At each
//  cell, either take it normally (carrying k forward) or, if k>0, spend one
//  power to treat it as max(coins[i][j], 0).
class Solution
{
public:
    int maximumAmount(vector<vector<int>> &g)
    {
        int dp[500][3];
        const int h = g.size(), w = g[0].size();

        fill_n(dp[0], 3 * w, -500'000);
        fill_n(dp[0], 3, 0);

        for (int y = 0; y != h; ++y)
        {
            {
                constexpr int x = 0;
                int top[]{dp[x][0], dp[x][1], dp[x][2]};
                int v = g[y][x], v0 = max(v, 0);
                dp[x][0] = v + top[0];
                dp[x][1] = max(v + top[1], v0 + top[0]);
                dp[x][2] = max(v + top[2], v0 + top[1]);
            }

            for (int x = 1; x != w; ++x)
            {
                int top[]{dp[x][0], dp[x][1], dp[x][2]};
                int v = g[y][x], v0 = max(v, 0);
                dp[x][0] = max(v + dp[x - 1][0], v + top[0]);
                dp[x][1] = max(max(v + dp[x - 1][1], v + top[1]),
                               max(v0 + dp[x - 1][0], v0 + top[0]));
                dp[x][2] = max(max(v + dp[x - 1][2], v + top[2]),
                               max(v0 + dp[x - 1][1], v0 + top[1]));
            }
        }

        return dp[w - 1][2];
    }
};