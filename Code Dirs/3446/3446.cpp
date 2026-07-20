// Link: https://leetcode.com/problems/sort-matrix-by-diagonals/description/

#include <bits/stdc++.h>
using namespace std;

int diag[10];
class Solution
{
public:
    // TC: O(n^2 log n) where n is the size of the grid
    // SC: O(n) where n is the size of the grid
    //  Approach:
    //  1. Iterate through the diagonals of the grid from top-right to bottom-left
    //  2. For each diagonal, store the elements in a temporary array and sort them
    //  3. Place the sorted elements back into the grid
    //  4. Repeat the process for the diagonals from bottom-left to top-right
    //  5. Return the sorted grid
    static vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        for (int d = n - 2; d > 0; d--)
        {
            for (int i = 0; i < n - d; i++)
                diag[i] = grid[i][i + d];
            sort(diag, diag + (n - d));
            for (int i = 0; i < n - d; i++)
                grid[i][i + d] = diag[i];
        }
        for (int d = 0; d < n - 1; d++)
        {
            for (int j = 0; j < n - d; j++)
                diag[j] = grid[j + d][j];
            sort(diag, diag + (n - d), greater<>());
            for (int j = 0; j < n - d; j++)
                grid[j + d][j] = diag[j];
        }
        return grid;
    }
};