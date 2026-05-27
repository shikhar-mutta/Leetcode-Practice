// Link: https://leetcode.com/problems/reshape-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c));
        int m = mat.size(), n = mat[0].size();
        // check if reshape is possible
        if (m * n != r * c)
            return mat;
        // reshape the matrix
        for (int i = 0; i < m * n; i++)
        { // map the elements from the original matrix to the new matrix
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};