// Link: https://leetcode.com/problems/shift-2d-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        k = k % (m * n); // Calculate the effective number of shifts needed

        vector<vector<int>> result(m, vector<int>(n)); // Create a new grid to store the shifted values

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {                                                // imp formula : (i * n + j + k) % (m * n)
                int newPos = (i * n + j + k) % (m * n);      // Calculate the new position for each element
                result[newPos / n][newPos % n] = grid[i][j]; // Place the element in its new position
            }
        }

        return result; // Return the shifted grid
    }
};
