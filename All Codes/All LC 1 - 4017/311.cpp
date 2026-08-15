// Link: https://leetcode.com/problems/sparse-matrix-multiplication/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*k*n) worst case, faster in practice by skipping zero entries  SC: O(m*n)
// Approach: standard matrix multiply, but skip multiply-add when mat1[i][k] == 0
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int p = 0; p < k; p++) {
                if (mat1[i][p] == 0) continue;
                for (int j = 0; j < n; j++) {
                    res[i][j] += mat1[i][p] * mat2[p][j];
                }
            }
        }
        return res;
    }
};
