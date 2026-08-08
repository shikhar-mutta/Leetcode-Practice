// Link: https://leetcode.com/problems/toeplitz-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(1)
// Approach: each cell must equal its top-left diagonal neighbor.
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
        return true;
    }
};
