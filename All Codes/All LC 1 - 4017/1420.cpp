// Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * k)  SC: O(n * m * k)
// Approach: dp[i][j][c] = number of arrays of length i, max value j, and cost c. For each length i, max value j, and cost c, we can either append a value <= j (which doesn't increase the cost) or append a value > j (which increases the cost by 1). We use prefix sums to efficiently calculate the number of ways to append values > j.
class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        int dp[n + 1][m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        const int mod = 1e9 + 7;
        for (int i = 1; i <= m; i++)
            dp[1][i][1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int c = 1; c <= k; c++)
            {
                int pref = 0;
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j][c] = (1LL * j * dp[i - 1][j][c] + pref) % (mod);
                    pref += dp[i - 1][j][c - 1];
                    if (pref >= mod)
                        pref -= mod;
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= m; j++)
            ans = (ans + dp[n][j][k]) % mod;
        return ans;
    }
};