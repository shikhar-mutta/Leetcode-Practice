// Link: https://leetcode.com/problems/knight-probability-in-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(k * n^2) where k is the number of moves and n is the size of the chessboard. We iterate through each cell of the chessboard for each move.
    // SC: O(n^2) for the dp array that stores the probabilities for each cell on the chessboard.
    //  Approach:
    //  1. We use dynamic programming to calculate the probability of the knight being on the chessboard after k moves.
    //  2. We initialize a 2D dp array where dp[r][c] represents the probability of the knight being on cell (r, c) after the current number of moves.
    //  3. We iterate through each move, updating the dp array based on the knight's possible moves. For each cell, we distribute its probability to its valid knight moves.
    //  4. After k moves, we sum up the probabilities of all cells to get the final probability of the knight being on the chessboard.
    //  5. Finally, we return the total probability.
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;

        int dirs[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        for (int step = 0; step < k; step++)
        {
            vector<vector<double>> ndp(n, vector<double>(n, 0.0));
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (dp[r][c] == 0.0)
                        continue;
                    for (auto &d : dirs)
                    {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                        {
                            ndp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = ndp;
        }

        double total = 0.0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                total += dp[r][c];
            }
        }
        return total;
    }
};