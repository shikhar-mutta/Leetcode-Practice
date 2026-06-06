// Link: https://leetcode.com/problems/modify-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n*m) SC: O(m*n)
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans = matrix;
        int max, row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == -1)
                {
                    max = 0;
                    for (int k = 0; k < row; k++)
                        if (matrix[k][j] > max)
                            max = matrix[k][j];

                    ans[i][j] = max;
                }
        return ans;
    }
};
