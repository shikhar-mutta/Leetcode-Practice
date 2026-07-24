// Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) SC: O(m*n)
    //  Approach:
    //   1. We will create a matrix of size m*n and initialize it with 0.
    //   2. We will iterate through the rowSum and colSum and fill the matrix with the minimum of rowSum[i] and colSum[j].
    //   3. We will update the rowSum[i] and colSum[j] accordingly.
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum)
    {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            int v = min(rowSum[i], colSum[j]);
            matrix[i][j] = v;
            rowSum[i] -= v;
            colSum[j] -= v;
            if (rowSum[i] == 0)
            {
                i++;
            }
            if (colSum[j] == 0)
            {
                j++;
            }
        }
        return matrix;
    }
};