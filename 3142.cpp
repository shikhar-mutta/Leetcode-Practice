// Link: https://leetcode.com/problems/check-if-grid-satisfies-conditions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//TC: O(rows * cols), SC: O(1)
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();

        // each cell must equal the one below it (all columns, rows 0..rows-2)
        for (int i = 0; i < rows - 1; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] != grid[i + 1][j])
                    return false;

        // adjacent columns must differ (all rows, cols 0..cols-2)
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols - 1; j++)
                if (grid[i][j] == grid[i][j + 1])
                    return false;

        return true;
    }
};
