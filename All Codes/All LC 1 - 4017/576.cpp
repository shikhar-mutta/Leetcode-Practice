// Link: https://leetcode.com/problems/out-of-boundary-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * maxMove), where m is the number of rows, n is the number of columns, and maxMove is the maximum number of moves allowed. We explore all possible paths from each cell for up to maxMove moves.
// SC: O(m * n * maxMove), where m is the number of rows, n is the number of columns, and maxMove is the maximum number of moves allowed. We use a 3D array dp to store the number of paths from each cell for each number of moves
// Approach:
//   1. We define a recursive function dfs that takes the current position (r, c), the number of remaining moves, and the grid dimensions (m, n) as input.
//   2. If the current position is out of bounds, we return 1, indicating that we have found a valid path that goes out of the grid.
//   3. If there are no remaining moves, we return 0, indicating that we cannot move further.
//   4. We use memoization to store the results of previously computed states in a 3D array dp, where dp[r][c][moves] represents the number of paths from cell (r, c) with the given number of remaining moves.
//   5. We recursively explore all four possible directions (up, down, left, right) from the current position and accumulate the number of valid paths.
//   6. Finally, we return the total number of valid paths modulo 10^9 + 7 to avoid overflow.
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int dp[51][51][51];
    int dfs(int m, int n, int moves, int r, int c)
    {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 1;
        if (moves == 0)
            return 0;
        if (dp[r][c][moves] != -1)
            return dp[r][c][moves];
        long long ans = 0;
        ans = (ans + dfs(m, n, moves - 1, r + 1, c)) % MOD;
        ans = (ans + dfs(m, n, moves - 1, r - 1, c)) % MOD;
        ans = (ans + dfs(m, n, moves - 1, r, c + 1)) % MOD;
        ans = (ans + dfs(m, n, moves - 1, r, c - 1)) % MOD;
        return dp[r][c][moves] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }
};