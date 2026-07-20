// Link: https://leetcode.com/problems/maximal-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(M*N) SC: O(M*N)
    //   Approach:
    //   1. We can use dynamic programming to solve this problem. We can create a 2D array dp of size (m+1) x (n+1) where dp[i][j] represents the side length of the largest square whose bottom-right corner is at (i,j).
    //   2. We can initialize the first row and first column of dp   to 0. Then, we can iterate through the matrix from bottom-right to top-left and update dp[i][j] as follows:
    //      - If matrix[i][j] == '0', then dp[i][j] = 0.
    //      - If matrix[i][j] == '1', then dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]).
    //   3. We can keep track of the maximum value of dp[i][j] and return its square as the final answer.
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = 1 + min(min(dp[i + 1][j + 1], dp[i][j + 1]), dp[i + 1][j]);
                    ans = max(ans, dp[i][j] * dp[i][j]);
                }
            }
        }

        return ans;
    }
};
