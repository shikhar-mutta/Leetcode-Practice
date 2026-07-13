// Link: https://leetcode.com/problems/sort-the-matrix-diagonally/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m * n * log(min(m, n))) where m is the number of rows and n is the number of columns.
    // SC: O(m * n) for storing the diagonals in a separate data structure.
    // Approach:
    // 1. Create a vector of vectors to store the diagonals of the matrix.
    // 2. Iterate through the matrix and for each element, calculate its diagonal index using the formula i - j + n - 1, where i is the row index, j is the column index, and n is the number of columns. Push the element into the corresponding diagonal vector.
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        // Cells on the same diagonal share i - j; offset by n-1 to index from 0.
        vector<vector<int>> diag(m + n - 1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                diag[i - j + n - 1].push_back(mat[i][j]);
        for (auto &d : diag)
            sort(d.begin(), d.end(), greater<int>());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                auto &d = diag[i - j + n - 1];
                mat[i][j] = d.back();
                d.pop_back();
            }
        return mat;
    }
};
