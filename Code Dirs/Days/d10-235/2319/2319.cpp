// Link: https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Brute Force.
    // TC: O(N^2). SC: O(1).
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        bool isXMatrix = true;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Check Main & Secondary Diagonal Elements.
                if ((i == j || i + j == n - 1) && grid[i][j] == 0)
                {
                    isXMatrix = false;
                    break;
                }
                // Check Non-Diagonal Elements.
                else if (i != j && i + j != n - 1 && grid[i][j] != 0)
                {
                    isXMatrix = false;
                    break;
                }
            }
            // If the matrix is not an X-Matrix, then break the loop.
            if (!isXMatrix)
                break;
        }

        return isXMatrix;
    }
};
