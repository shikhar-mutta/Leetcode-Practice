// Link: https://leetcode.com/problems/sort-the-matrix-diagonally/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                diag[i - j].push_back(mat[i][j]);

        for (auto& [k, v] : diag) sort(v.begin(), v.end());

        unordered_map<int, int> idx;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = diag[i - j][idx[i - j]++];
            }
        }
        return mat;
    }
};
