// Link: https://leetcode.com/problems/maximize-grid-happiness/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * 3^n * I * E) where m is the number of rows, n is the number of columns, I is the number of introverts, and E is the number of extroverts
// SC: O(m * n * 3^n * I * E) where m is the number of rows, n is the number of columns, I is the number of introverts, and E is the number of extroverts
//  Approach: We can use a backtracking approach to try to place introverts and extroverts in the grid. We can represent the state of the grid using a bitmask, where each cell can be empty, have an introvert, or have an extrovert. We can use a recursive function to try to place introverts and extroverts in the grid, and keep track of the maximum happiness we can achieve. We can use memoization to avoid recalculating the same state multiple times. The happiness of each cell is calculated based on the number of introverts and extroverts in the neighboring cells. The final answer is the maximum happiness we can achieve by placing all introverts and extroverts in the grid.
class Solution
{
public:
    int dp[26][7][7][243];
    int rows, cols;
    int power3[6];

    int getInteractionCost(int p1, int p2)
    {
        if (p1 == 0 || p2 == 0)
            return 0;

        int diff = 0;

        if (p1 == 1)
            diff -= 30;
        else
            diff += 20;

        if (p2 == 1)
            diff -= 30;
        else
            diff += 20;

        return diff;
    }

    int solve(int pos, int intro, int extro, int mask)
    {
        if (pos == rows * cols)
            return 0;

        if (dp[pos][intro][extro][mask] != -1)
            return dp[pos][intro][extro][mask];

        int c = pos % cols;

        // up neighbour
        int up = mask / power3[cols - 1];

        // left neighbour
        int left = (c == 0) ? 0 : (mask % 3);

        // shift mask
        int newMask = (mask % power3[cols - 1]) * 3;

        int ans = solve(pos + 1, intro, extro, newMask);

        // Place Introvert
        if (intro)
        {
            int gain = 120;
            gain += getInteractionCost(1, up);
            gain += getInteractionCost(1, left);

            ans = max(ans,
                      gain + solve(pos + 1,
                                   intro - 1,
                                   extro,
                                   newMask + 1));
        }

        // Place Extrovert
        if (extro)
        {
            int gain = 40;
            gain += getInteractionCost(2, up);
            gain += getInteractionCost(2, left);

            ans = max(ans,
                      gain + solve(pos + 1,
                                   intro,
                                   extro - 1,
                                   newMask + 2));
        }

        return dp[pos][intro][extro][mask] = ans;
    }

    int getMaxGridHappiness(int m, int n,
                            int introvertsCount,
                            int extrovertsCount)
    {

        rows = m;
        cols = n;

        power3[0] = 1;
        for (int i = 1; i <= 5; i++)
            power3[i] = power3[i - 1] * 3;

        memset(dp, -1, sizeof(dp));

        return solve(0, introvertsCount, extrovertsCount, 0);
    }
};