// Link: https://leetcode.com/problems/range-sum-query-2d-immutable/description/

#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    // TC: O(m*n)
    // SC: O(m*n)
    //  Approach:
    // 1. We can use prefix sum to solve this problem.
    // 2. We can create a prefix sum matrix where prefix[i][j] is the sum of all elements in the rectangle from (0,0) to (i-1,j-1).
    // 3. Then we can use the prefix sum matrix to calculate the sum of any submatrix in O(1) time.
    // 4. The sum of the submatrix from (row1,col1) to (row2,col2) can be calculated as:
    //    sum = prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1]
    // 5. This is because we are adding the sum of the rectangle from (0,0) to (row2,col2) and subtracting the sum of the rectangles that are not part of the submatrix.
    // 6. The time complexity of the constructor is O(m*n) and the time complexity of the sumRegion function is O(1).
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                prefix[i + 1][j + 1] = matrix[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }

private:
    vector<vector<int>> prefix;
};
