// Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n^2) where n is the number of rows in the matrix
    //  Approach:
    // 1. We can use a prefix sum approach to solve this problem. We can create a prefix sum matrix where each cell (i,j) contains the sum of all elements in the submatrix from (0,0) to (i,j). We can then iterate through each cell in the matrix and check if the sum of the square submatrix with side length a is less than or equal to the threshold. If it is, we can increment a and check again until we find the maximum side length.
    // 2. We can use the prefix sum matrix to calculate the sum of the square submatrix in O(1) time by using the formula: sum = sumAtPoint[i + a + 1][j + a + 1] - sumAtPoint[i + a + 1][j] - sumAtPoint[i][j + a + 1] + sumAtPoint[i][j].
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        vector<vector<int>> sumAtPoint(mat.size() + 1,
                                       vector<int>(mat[0].size() + 1, 0));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                sumAtPoint[i + 1][j + 1] = mat[i][j] + sumAtPoint[i][j + 1] +
                                           sumAtPoint[i + 1][j] -
                                           sumAtPoint[i][j];
            }
        }

        int a = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            if (i + a >= mat.size())
            {
                break;
            }
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (i + a >= mat.size() || j + a >= mat[0].size())
                {
                    break;
                }
                int squareSum = sumAtPoint[i + a + 1][j + a + 1] -
                                sumAtPoint[i + a + 1][j] -
                                sumAtPoint[i][j + a + 1] + sumAtPoint[i][j];
                while (squareSum <= threshold)
                {
                    a++;
                    if (i + a >= mat.size() || j + a >= mat[0].size())
                    {
                        break;
                    }
                    squareSum = sumAtPoint[i + a + 1][j + a + 1] -
                                sumAtPoint[i + a + 1][j] -
                                sumAtPoint[i][j + a + 1] + sumAtPoint[i][j];
                }
            }
        }
        return a;
    }
};