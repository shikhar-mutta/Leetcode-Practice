// Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*k), SC: O(m*n*k)
//  Approach: dp[i][j][l] denotes number of paths from i,j to m-1,n-1 with reminder l. We can move either down or right. So we can use bottom up approach to fill the dp table. The answer will be dp[0][0][0] as we need to find number of paths from 0,0 to m-1,n-1 with reminder 0.
#define ll long long int
class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        ll m = grid.size();
        ll n = grid[0].size();
        ll dp[m][n][k];
        ll mod = 1000000007;
        // dp[i][j][l] denotes no of paths from i,j to m-1,n-1 with reminder k

        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                for (ll l = 0; l < k; l++)
                {
                    dp[i][j][l] = 0;
                }
            }
        }

        dp[m - 1][n - 1][grid[m - 1][n - 1] % k] = 1;

        for (ll i = m - 1; i >= 0; i--)
        {
            for (ll j = n - 1; j >= 0; j--)
            {
                if (i == m - 1)
                {
                    if (j < n - 1)
                    {
                        for (ll l = 0; l < k; l++)
                        {
                            ll existing = grid[i][j] % k;
                            ll desired = l;
                            if (desired >= existing)
                            {
                                dp[i][j][l] = dp[i][j + 1][l - existing];
                            }
                            else
                            {
                                dp[i][j][l] = dp[i][j + 1][l + k - existing];
                            }
                        }
                    }
                }
                else if (j == n - 1)
                {
                    if (i < m - 1)
                    {
                        for (ll l = 0; l < k; l++)
                        {
                            ll existing = grid[i][j] % k;
                            ll desired = l;
                            if (desired >= existing)
                            {
                                dp[i][j][l] = dp[i + 1][j][l - existing];
                            }
                            else
                            {
                                dp[i][j][l] = dp[i + 1][j][l + k - existing];
                            }
                        }
                    }
                }
                else
                {
                    for (ll l = 0; l < k; l++)
                    {
                        ll existing = grid[i][j] % k;
                        ll desired = l;
                        if (desired >= existing)
                        {
                            dp[i][j][l] = (dp[i + 1][j][l - existing] +
                                           dp[i][j + 1][l - existing]) %
                                          mod;
                        }
                        else
                        {
                            dp[i][j][l] = (dp[i + 1][j][l + k - existing] +
                                           dp[i][j + 1][l + k - existing]) %
                                          mod;
                        }
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};
