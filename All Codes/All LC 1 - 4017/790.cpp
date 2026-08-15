// Link: https://leetcode.com/problems/domino-and-tromino-tiling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of columns in the board.
    // SC: O(n), for storing the results of subproblems in the dp array
    // Approach:
    //  1. We use dynamic programming to solve the problem. We define a 1D array dp[i] to store the number of ways to tile a 2 x i board.
    //  2. We initialize the base cases: dp[0] = 1 (1 way to tile a 2 x 0 board), dp[1] = 1 (1 way to tile a 2 x 1 board), and dp[2] = 2 (2 ways to tile a 2 x 2 board).
    //  3. We use a loop to calculate the number of ways to tile a 2 x i board for i from 3 to n using the recurrence relation: dp[i] = 2 * dp[i - 1] + dp[i - 3]. The first term accounts for placing a vertical domino in the last column, and the second term accounts for placing a tromino in the last three columns.
    //  4. We return dp[n] as the final answer, which represents the number of ways to tile a 2 x n board.
    //  Note: The result is taken modulo 10^9 + 7 to prevent overflow and to meet the problem's constraints.
    int numTilings(int n)
    {
        const int MOD = 1e9 + 7;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
        return dp[n];
    }
};
