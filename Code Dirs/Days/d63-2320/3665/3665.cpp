// Link: https://leetcode.com/problems/twisted-mirror-path-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(n)
//  Approach: Push-DP in row-major order. From each reachable non-mirror
//  cell, resolve a "right" attempt and a "down" attempt: repeatedly step
//  in the current direction, and each time the target is a mirror, flip
//  direction and continue from the mirror's position (per the reflection
//  chain rule), until landing on a non-mirror cell or going out of bounds.
//  Push dp[i][j] forward into both resolved landing cells.
class Solution
{
public:
    int uniquePaths(vector<vector<int>> &grid)
    {
        int mod = 1e9 + 7;
        int m = size(grid), n = size(grid[0]);
        vector<int> dp(n);
        dp[0] = 1;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0, prev = 0; c < n; ++c)
            {
                if (grid[r][c] == 0)
                    dp[c] = (dp[c] + prev) % mod, prev = dp[c];
                else
                    swap(dp[c], prev);
            }
        }
        return dp[n - 1];
    }
};