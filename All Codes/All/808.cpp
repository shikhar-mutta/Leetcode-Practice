// Link: https://leetcode.com/problems/soup-servings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), where n is the number of servings of soup A and B.
// SC: O(n^2), for storing the results of subproblems in the dp array.
// Approach:
// 1. We use dynamic programming to solve the problem. We define a 2D array dp[a][b] to store the probability of soup A being empty first when there are a servings of soup A and b servings of soup B.
// 2. We initialize the base cases: if a <= 0 and b <= 0, the probability is 0.5; if a <= 0, the probability is 1.0; if b <= 0, the probability is 0.0.
// 3. We use a recursive function solve(a, b) to calculate the probability for each state (a, b) using the four possible operations. We take the average of the probabilities of the four operations and store it in dp[a][b].
// 4. We call the solve function with the initial servings of soup A and B, which is n. We also handle the case when n is greater than or equal to 4800, in which case we return 1.0 as the probability of soup A being empty first is almost certain.
// 5. We return the result of the solve function as the final answer.
class Solution
{
public:
    double dp[201][201];

    double solve(int a, int b)
    {
        if (a <= 0 && b <= 0)
            return 0.5;

        if (a <= 0)
            return 1.0;

        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        return dp[a][b] =
                   0.25 * (solve(a - 4, b) +
                           solve(a - 3, b - 1) +
                           solve(a - 2, b - 2) +
                           solve(a - 1, b - 3));
    }

    double soupServings(int n)
    {
        if (n >= 4800)
            return 1.0;

        fill(&dp[0][0], &dp[0][0] + 201 * 201, -1.0);

        n = (n + 24) / 25;

        return solve(n, n);
    }
};