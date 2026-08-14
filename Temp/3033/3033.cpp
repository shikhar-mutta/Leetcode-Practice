// Link: https://leetcode.com/problems/modify-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> colMax(m, -1);
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                colMax[j] = max(colMax[j], matrix[i][j]);
        vector<vector<int>> res = matrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (res[i][j] == -1) res[i][j] = colMax[j];
        return res;
    }
};
