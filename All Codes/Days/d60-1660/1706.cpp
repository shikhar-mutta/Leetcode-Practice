// Link: https://leetcode.com/problems/where-will-the-ball-fall/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) where m is the number of rows and n is the number of columns in the grid.
    // SC: O(n) for storing the result of the ball's final positions.
    // Approach:
    //   1. For each ball starting at column 'start', simulate its path through the grid.
    //   2. For each row, calculate the next column based on the current cell's direction (1 for right, -1 for left).
    //   3. If the ball goes out of bounds or gets stuck in a V-shaped trap, mark its final position as -1.
    //   4. Store the final position of each ball in the result vector and return it.
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int start = 0; start < n; ++start)
        {
            int c = start;
            for (int r = 0; r < m; ++r)
            {
                int next = c + grid[r][c];
                if (next < 0 || next >= n || grid[r][next] != grid[r][c])
                {
                    c = -1;
                    break;
                }
                c = next;
            }
            res[start] = c;
        }
        return res;
    }
};