// Link: https://leetcode.com/problems/set-matrix-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        // We can use the first row and column to mark the rows and columns that need to be set to zero.
        bool frZ = false, fcZ = false;
        // Check if the first row and column have any zeros, and mark them accordingly.
        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] == 0)
            {
                fcZ = true;
                break;
            };
        }
        // Check if the first row has any zeros, and mark it accordingly.
        for (int i = 0; i < c; i++)
        {
            if (matrix[0][i] == 0)
            {
                frZ = true;
                break;
            };
        }

        // Mark the rows and columns that need to be set to zero using the first row and column.
        for (int ir = 1; ir < r; ir++)
        {
            for (int ic = 1; ic < c; ic++)
            {
                if (matrix[ir][ic] == 0)
                {
                    matrix[ir][0] = 0;
                    matrix[0][ic] = 0;
                }
            }
        }

        for (int ir = 1; ir < r; ir++)
        {
            for (int ic = 1; ic < c; ic++)
            {
                if (matrix[0][ic] == 0 || matrix[ir][0] == 0)
                {
                    matrix[ir][ic] = 0;
                }
            }
        }

        // Finally, set the first row and column to zero if they were marked.
        if (frZ)
        {
            for (int ic = 0; ic < c; ic++)
                matrix[0][ic] = 0;
        }
        // Finally, set the first column to zero if it was marked.
        if (fcZ)
        {
            for (int ir = 0; ir < r; ir++)
                matrix[ir][0] = 0;
        }
    }
};