// Link: https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * V) SC: O(m * n * V), V = xor-value range (32)
//  Approach: DP over dp[i][j][x] = number of right/down paths from (0,0)
//  to (i,j) whose cumulative XOR equals x. Transition combines the ways
//  coming from above and from the left, XOR-ing in grid[i][j]. Answer is
//  dp[m-1][n-1][k].
const int MOD = 1e9 + 7;
class Solution
{
public:
    int countPathsWithXorValue(vector<vector<int>> &nums, int k)
    {
        int n = nums.size(), m = nums[0].size();
        int dp[n + 1][m + 1][16];
        memset(dp, 0, sizeof(dp));
        dp[n - 1][m - 1][nums[n - 1][m - 1]] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    continue;
                for (int xr = 0; xr < 16; xr++)
                {
                    // int ntake = (dp[i][j+1][xr] + dp[i+1][j][xr])%MOD;
                    int take = (dp[i][j + 1][xr ^ nums[i][j]] +
                                dp[i + 1][j][xr ^ nums[i][j]]) %
                               MOD;
                    dp[i][j][xr] = (take) % MOD;
                }
            }
        }
        return dp[0][0][k];
    }
};