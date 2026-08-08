// Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowMin(m, INT_MAX), colMax(n, INT_MIN);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        vector<int> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                    res.push_back(matrix[i][j]);
        return res;
    }
};
