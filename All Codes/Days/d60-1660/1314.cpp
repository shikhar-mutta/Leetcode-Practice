// Link: https://leetcode.com/problems/matrix-block-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) SC: O(m*n) where m is the number of rows and n is the number of columns in the matrix
    // Approach:
    //   1. We can use a prefix sum approach to solve this problem. We can create a prefix sum matrix that stores the sum of all elements in the submatrix from (0,0) to (i,j) for each cell (i,j) in the original matrix.
    //   2. We can then use the prefix sum matrix to calculate the sum of the elements in the block of size (2k+1)x(2k+1) centered at each cell (i,j) in the original matrix. The sum of the elements in the block can be calculated using the formula:
    //      sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]
    //      where (r1,c1) is the top-left corner of the block and (r2,c2) is the bottom-right corner of the block. We can calculate (r1,c1) and (r2,c2) using the following formulas:
    //      r1 = max(0, i-k), c1 = max(0, j-k), r2 = min(m-1, i+k), c2 = min(n-1, j+k)
    //   3. Finally, we can return the resulting matrix that contains the sum of the elements in the block for each cell (i,j) in the original matrix.
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int r1 = max(0, i - k);
                int c1 = max(0, j - k);

                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);

                ans[i][j] = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] -
                            prefix[r2 + 1][c1] + prefix[r1][c1];
            }
        }
        return ans;
    }
};