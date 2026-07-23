// Link: https://leetcode.com/problems/stone-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &piles, vector<int> &suffix, int i, int M, int n,
              vector<vector<int>> &dp)
    {
        if (i >= n)
            return 0;
        if (2 * M >= n - i)
            return suffix[i];
        if (dp[i][M] != -1)
            return dp[i][M];
        int ans = 0;
        for (int X = 1; X <= 2 * M; X++)
        {
            ans = max(ans, suffix[i] -
                               solve(piles, suffix, i + X, max(M, X), n, dp));
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> suffix(n);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];
        return solve(piles, suffix, 0, 1, n, dp);
    }
};