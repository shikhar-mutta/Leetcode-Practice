// Link: https://leetcode.com/problems/reshape-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(r*c)
// Approach: flatten by index math, refill into the new shape if the total
// element count matches
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;

        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};
