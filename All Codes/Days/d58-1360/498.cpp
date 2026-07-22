// Link: https://leetcode.com/problems/diagonal-traverse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) where m is the number of rows and n is the number of columns in the matrix
    // SC: O(1)
    // Approach:
    //  1. Initialize variables to keep track of the current row and column, as well as a boolean variable to indicate the direction of traversal (up or down).
    //  2. Use a while loop to traverse the matrix until all elements have been added to the result vector.
    //  3. Inside the loop, add the current element to the result vector and update the row and column indices based on the current direction of traversal.
    //  4. If the current direction is up, check if the current column is at the last column or if the current row is at the first row. If either condition is true, change the direction to down and update the row and column indices accordingly. Otherwise, move up diagonally by decrementing the row index and incrementing the column index.
    //  5. If the current direction is down, check if the current row is at the last row or if the current column is at the first column. If either condition is true, change the direction to up and update the row and column indices accordingly. Otherwise, move down diagonally by incrementing the row index and decrementing the column index.
    //  6. Return the result vector containing the elements of the matrix in diagonal order.
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int r = 0, c = 0;
        bool up = true;
        while ((int)res.size() < m * n)
        {
            res.push_back(mat[r][c]);
            if (up)
            {
                if (c == n - 1)
                {
                    r++;
                    up = false;
                }
                else if (r == 0)
                {
                    c++;
                    up = false;
                }
                else
                {
                    r--;
                    c++;
                }
            }
            else
            {
                if (r == m - 1)
                {
                    c++;
                    up = true;
                }
                else if (c == 0)
                {
                    r++;
                    up = true;
                }
                else
                {
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
