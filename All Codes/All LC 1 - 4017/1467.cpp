// Link: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * k) SC: O(n^2 * k)
    // Approach: Use dynamic programming to find the probability of two boxes having the same number of distinct balls. We can use a 3D dp array where dp[i][j][diff] represents the number of ways to distribute the first i types of balls into two boxes such that box 1 has j balls and the difference in the number of distinct balls between the two boxes is diff. We iterate through each type of ball and update the dp array accordingly. Finally, we return dp[k][n][k] / c[n * 2][n] which represents the probability of two boxes having the same number of distinct balls.
    double getProbability(vector<int> &balls)
    {
        int n = accumulate(balls.begin(), balls.end(), 0) / 2;
        int mx = *max_element(balls.begin(), balls.end());
        int m = max(mx, n << 1);
        long long c[m + 1][m + 1];
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= m; ++i)
        {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j)
            {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        int k = balls.size();
        long long f[k][n + 1][k << 1 | 1];
        memset(f, -1, sizeof(f));
        function<long long(int, int, int)> dfs = [&](int i, int j,
                                                     int diff) -> long long
        {
            if (i >= k)
            {
                return j == 0 && diff == k ? 1 : 0;
            }
            if (j < 0)
            {
                return 0;
            }
            if (f[i][j][diff] != -1)
            {
                return f[i][j][diff];
            }
            long long ans = 0;
            for (int x = 0; x <= balls[i]; ++x)
            {
                int y = x == balls[i] ? 1 : (x == 0 ? -1 : 0);
                ans += dfs(i + 1, j - x, diff + y) * c[balls[i]][x];
            }
            return f[i][j][diff] = ans;
        };
        return dfs(0, n, k) * 1.0 / c[n << 1][n];
    }
};