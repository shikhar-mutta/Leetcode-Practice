// Link: https://leetcode.com/problems/magic-squares-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), where n is the number of rows and m is the number of columns in the grid.
    // SC: O(1), as we are using a constant amount of extra space.
    // Approach:
    //  1. We iterate through each cell in the grid and check if it is the top-left corner of a 3x3 magic square.
    //  2. We check if the 3x3 square contains all the numbers from 1 to 9 and if the sum of each row, column, and diagonal is equal to 15.
    //  3. If it is a magic square, we increment the count and return the total count at the end.
    //  4. We use a set to keep track of the numbers we have seen in the 3x3 square to ensure that all numbers are unique and within the range of 1 to 9.
    //  5. We check the sum of each row, column, and diagonal to ensure that they all equal 15.
    bool isMagic(vector<vector<int>> &grid, int r, int c)
    {
        set<int> seen;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                int v = grid[r + i][c + j];
                if (v < 1 || v > 9 || !seen.insert(v).second)
                    return false;
            }

        for (int i = 0; i < 3; i++)
        {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != 15)
                return false;
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != 15)
                return false;
        }
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15)
            return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int r = 0; r + 2 < rows; r++)
            for (int c = 0; c + 2 < cols; c++)
                if (isMagic(grid, r, c))
                    count++;
        return count;
    }
};
