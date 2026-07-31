// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * k * (m + n))  SC: O(m * n * k)
// Approach: Use dynamic programming to count the number of ways to cut the pizza. We can use a 3D dp array where dp[r][c][k] represents the number of ways to cut the pizza starting from cell (r, c) with k cuts remaining. We can precompute the number of apples in each submatrix using a suffix sum array. For each cell, we can try making horizontal and vertical cuts and recursively count the number of ways to cut the remaining pizza.
class Solution
{
public:
    static const int MOD = 1000000007;
    int m, n;
    int pre[55][55];
    int dp[55][55][11];

    int solve(int r, int c, int k)
    {
        if (pre[r][c] == 0)
            return 0;
        if (k == 0)
            return 1;

        if (dp[r][c][k] != -1)
            return dp[r][c][k];

        long long ans = 0;

        // Horizontal cuts
        for (int nr = r + 1; nr < m; nr++)
        {
            if (pre[r][c] - pre[nr][c] > 0)
            {
                ans = (ans + solve(nr, c, k - 1)) % MOD;
            }
        }

        // Vertical cuts
        for (int nc = c + 1; nc < n; nc++)
        {
            if (pre[r][c] - pre[r][nc] > 0)
            {
                ans = (ans + solve(r, nc, k - 1)) % MOD;
            }
        }

        return dp[r][c][k] = ans;
    }

    int ways(vector<string> &pizza, int k)
    {
        m = pizza.size();
        n = pizza[0].size();

        memset(pre, 0, sizeof(pre));
        memset(dp, -1, sizeof(dp));

        // Suffix sum of apples
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                pre[i][j] = (pizza[i][j] == 'A') + pre[i + 1][j] +
                            pre[i][j + 1] - pre[i + 1][j + 1];
            }
        }

        return solve(0, 0, k - 1);
    }
};