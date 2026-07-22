// Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), where n is the number of rows/columns in the grid.
    // SC: O(n), for storing the maximum values of each row and column.
    // Approach:
    // 1. We first find the maximum value of each row and column in the grid.
    // 2. Then, we iterate through each cell in the grid and calculate the maximum possible increase for that cell, which is the minimum of the maximum values of its row and column minus its current value.
    // 3. We sum up all the maximum possible increases to get the total increase that can be made to the grid while keeping the skyline unchanged.
    // 4. Finally, we return the total increase.
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> rowMax(n, 0), colMax(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return total;
    }
};
