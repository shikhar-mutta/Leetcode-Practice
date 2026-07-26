// Link: https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            // Swap elements across the diagonal
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        // Reverse each row
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};