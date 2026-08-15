// Link: https://leetcode.com/problems/stone-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the number of piles
    // SC: O(n^2) for the dp array
    //   Approach:
    //    1. Use a recursive function with memoization to calculate the maximum number of stones the first player can get starting from index i with a given M.
    //    2. Use a suffix sum array to quickly calculate the total number of stones remaining from index i to the end of the piles.
    //    3. For each possible X (number of piles to take), calculate the maximum stones the first player can get by taking X piles and then subtracting the maximum stones the second player can get from the remaining piles.
    //    4. Store the result in the dp array to avoid recalculating for the same state.
    //    5. Return the maximum number of stones the first player can get starting from index 0 with M = 1.
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