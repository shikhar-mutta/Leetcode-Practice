// Link: https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) . SC: O(1) .
    int minimumOperations(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size(), opr = 0;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 1; j < rows; j++)
            {
                if (grid[j][i] <= grid[j - 1][i])
                {
                    opr += grid[j - 1][i] - grid[j][i] + 1;
                    grid[j][i] = grid[j - 1][i] + 1;
                }
            }
        }
        return opr;
    }
};
