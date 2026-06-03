// Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using Hashing. TC: O(n^2), SC: O(n)
    // Its like Sudoku each row and column should contain all numbers from 1 to n
    // without repetition.
    bool checkValid(vector<vector<int>> &matrix)
    {
        bool valid = true;

        int n = matrix.size(); // n is number of rows and columns in the matrix

        // Check each row and column for the presence of numbers from 1 to n
        for (int i = 0; i < n; ++i)
        { // row & col to track the presence of numbers in the current row and column
            vector<bool> row(n + 1, false), col(n + 1, false);

            for (int j = 0; j < n; ++j)
            {
                // Check the current element in the row and column for validity
                if (matrix[i][j] < 1 || matrix[i][j] > n || row[matrix[i][j]])
                {
                    valid = false;
                    break;
                }
                row[matrix[i][j]] = true;
                // Check the current element in the row and column for validity
                if (matrix[j][i] < 1 || matrix[j][i] > n || col[matrix[j][i]])
                {
                    valid = false;
                    break;
                }
                col[matrix[j][i]] = true;
            }
            // If the current row or column is invalid, break out of the loop early
            if (!valid)
            {
                break;
            }
        }
        return valid;
    }
};
