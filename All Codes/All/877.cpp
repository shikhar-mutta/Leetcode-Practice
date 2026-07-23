// Link: https://leetcode.com/problems/stone-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach:
// 1. We use dynamic programming to solve this problem.
// 2. We create a 2D array dp where dp[i][j] represents the maximum score difference that the current player can achieve over the other player when playing optimally on the subarray piles[i...j].
// 3. We iterate through the array in reverse order and fill the dp array based on the choices of the current player.
// 4. The current player can choose either the leftmost pile or the rightmost pile, and the score difference is calculated accordingly.
// 5. Finally, we check if the maximum score difference for the entire array is greater than 0, which means the first player can win the game.
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> next(n), curr(n);
        for (int a = n - 1; a >= 0; a--)
        {
            for (int b = a; b < n; b++)
            {
                if (a == b)
                    curr[b] = -piles[a];
                else if ((b - a) % 2 == 1)
                {
                    curr[b] = max(piles[a] + next[b], piles[b] + curr[b - 1]);
                }
                else
                    curr[b] = max(-piles[a] + next[b], -piles[b] + curr[b - 1]);
            }
            next = curr;
        }
        return next[n - 1] > 0;
    }
};
