// Link: https://leetcode.com/problems/largest-1-bordered-square/description/

#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <vector>

class Solution
{
public:
    // TC: O(rows * cols * min(rows, cols)) where rows and cols are the dimensions of the grid
    // SC: O(rows * cols) for the left and top matrices
    //   Approach:
    //    1. Precompute two matrices, left and top, where left[r][c] stores the number of consecutive 1s to the left of (r, c) and top[r][c] stores the number of consecutive 1s above (r, c).
    //    2. Iterate through each cell in the grid, treating it as the bottom-right corner of a potential square.
    //    3. For each cell, determine the maximum possible side length of a square that can be formed with that cell as the bottom-right corner, which is the minimum of left[r][c] and top[r][c].
    //    4. For each potential side length, check if the corresponding top-left corner of the square has enough consecutive 1s to form a valid square. If it does, update the maximum side length found.
    //    5. Return the area of the largest square found, which is max_side * max_side.
    int largest1BorderedSquare(std::vector<std::vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // left[r][c] stores consecutive 1s to the left of (r, c)
        // top[r][c] stores consecutive 1s above (r, c)
        std::vector<std::vector<int>> left(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> top(rows, std::vector<int>(cols, 0));

        // Step 1: Precompute the DP prefix matrices
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 1)
                {
                    left[r][c] = (c == 0) ? 1 : left[r][c - 1] + 1;
                    top[r][c] = (r == 0) ? 1 : top[r - 1][c] + 1;
                }
            }
        }

        int max_side = 0;

        // Step 2: Check every cell as the bottom-right corner of a square
        for (int r = rows - 1; r >= 0; --r)
        {
            for (int c = cols - 1; c >= 0; --c)
            {
                // Find the maximum potential side length allowed by the bottom
                // and right edges
                int max_possible_side = std::min(left[r][c], top[r][c]);

                // Try descending side lengths down to our current max_side
                for (int len = max_possible_side; len > max_side; --len)
                {
                    // Check if the top edge and left edge are fully composed of
                    // 1s Top-right corner looking left, and Bottom-left corner
                    // looking up
                    if (left[r - len + 1][c] >= len &&
                        top[r][c - len + 1] >= len)
                    {
                        max_side = len;
                        break; // Found the largest possible square ending at
                               // this bottom-right cell
                    }
                }
            }
        }

        // Return total number of elements inside the grid submatrix
        return max_side * max_side;
    }
};