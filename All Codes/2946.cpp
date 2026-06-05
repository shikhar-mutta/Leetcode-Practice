// Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(m*n)
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> shifted(mat.size(), vector<int>(mat[0].size()));
        int rows = mat.size();
        int cols = mat[0].size();
        k %= cols; // Handle cases where k is larger than the number of columns
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (i % 2 == 0) // even row: left shift
                    shifted[i][j] = mat[i][(j - k + cols) % cols];
                else // odd row: right shift
                    shifted[i][j] = mat[i][(j + k) % cols];
        return shifted == mat;
    }
};
