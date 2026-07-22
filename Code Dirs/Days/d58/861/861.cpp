// Link: https://leetcode.com/problems/score-after-flipping-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(rows * cols) where rows is the number of rows in the grid and cols is the number of columns in the grid. We iterate through each cell of the grid once.
    // SC: O(1) as we are using a constant amount of space.
    // Approach:
    //  1. We first ensure that the first column has all 1s by flipping rows where the first element is 0. This is because the first column contributes the most to the score.
    //  2. Then, for each column, we count the number of 1s. If the number of 0s is greater than the number of 1s, we can flip the column to maximize the number of 1s.
    //  3. Finally, we calculate the total score by summing the values of each row interpreted as a binary number. The value of each row is calculated as the sum of 1s in each column multiplied by the corresponding power of 2 based on its position.
    int matrixScore(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++)
            if (grid[r][0] == 0)
                for (int c = 0; c < cols; c++)
                    grid[r][c] ^= 1;

        int total = 0;
        for (int c = 0; c < cols; c++)
        {
            int ones = 0;
            for (int r = 0; r < rows; r++)
                ones += grid[r][c];
            total += max(ones, rows - ones) * (1 << (cols - 1 - c));
        }
        return total;
    }
};
