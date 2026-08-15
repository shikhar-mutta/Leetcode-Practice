// Link: https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * min(n, x)), SC: O(n)
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the number of ways to choose j events from the first i events. We can initialize dp[0][0] = 1, and for each event i, we can iterate through the number of events j from 1 to min(i, x) and update dp[i][j] as follows: dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * (x - j + 1). Finally, we can return the sum of dp[n][j] for j from 1 to min(n, x).
long long s[1001][1001], mod = 1e9 + 7;
auto init = []
{
    s[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod;
    return 0;
}();

class Solution
{
public:
    int numberOfWays(int n, int x, int y)
    {
        long long res = 0, perm = 1, pow = 1;
        for (int i = 1; i <= min(n, x); i++)
        {
            perm = perm * (x - i + 1) % mod;
            pow = pow * y % mod;
            res = (res + perm * s[n][i] % mod * pow) % mod;
        }
        return res;
    }
};