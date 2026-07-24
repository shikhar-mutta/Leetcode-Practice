// Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) SC: O(m*n)
    // Approach:
    //  1. We will maintain two matrices mx and mn to keep track of the maximum and minimum product at each cell.
    //  2. We will initialize the first cell with the value of the grid and fill the first row and first column with the product of the previous cell and the current cell.
    //  3. For each cell, we will calculate the maximum and minimum product by considering the maximum and minimum product from the top and left cells and multiplying it with the current cell value.
    //  4. Finally, we will return the maximum product at the bottom-right cell if it is non-negative, otherwise we will return -1.
    int maxProductPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> mx(m, vector<long long>(n)),
            mn(m, vector<long long>(n));
        mx[0][0] = mn[0][0] = grid[0][0];

        for (int j = 1; j < n; ++j)
            mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];
        for (int i = 1; i < m; ++i)
            mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                long long v = grid[i][j];
                long long a = mx[i - 1][j] * v, b = mn[i - 1][j] * v;
                long long c = mx[i][j - 1] * v, d = mn[i][j - 1] * v;
                mx[i][j] = max(max(a, b), max(c, d));
                mn[i][j] = min(min(a, b), min(c, d));
            }
        }
        long long res = mx[m - 1][n - 1];
        return res < 0 ? -1 : res % 1000000007;
    }
};