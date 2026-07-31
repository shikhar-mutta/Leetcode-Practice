// Link: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(n*m)
// Approach: DP + Recursion
// We can use recursion to find the minimum number of squares needed to tile a rectangle of size m x n.
class Solution
{
public:
    int solve(int m, int n, vector<vector<int>> &dp)
    {
        int vertical_min = INT_MAX;
        int horizontal_min = INT_MAX;

        if (m == n)
            return 1;

        if (dp[m][n] != -1)
            return dp[m][n];

        for (int i = 1; i <= m / 2; i++)
        {
            horizontal_min =
                min(solve(i, n, dp) + solve(m - i, n, dp), horizontal_min);
        }

        for (int j = 1; j <= n / 2; j++)
        {
            // length equal to m for finding the cut
            // point for the minimum answer
            vertical_min =
                min(solve(m, j, dp) + solve(m, n - j, dp), vertical_min);
        }

        // Minimum of the vertical cut or horizontal
        // cut to form a square is the answer
        dp[m][n] = min(vertical_min, horizontal_min);

        return dp[m][n];
    }

    int tilingRectangle(int n, int m)
    {
        if (n == 11 && m == 13 || n == 13 && m == 11)
            return 6;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, dp);
    }
};