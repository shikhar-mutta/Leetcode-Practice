// Link: https://leetcode.com/problems/count-submatrices-with-all-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> height(rows, vector<int>(cols, 0));
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                height[i][j] = mat[i][j] == 0 ? 0 : (i > 0 ? height[i-1][j] + 1 : 1);
            }
        }

        int total = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    minHeight = min(minHeight, height[i][k]);
                    if (minHeight == 0) break;
                    total += minHeight;
                }
            }
        }
        return total;
    }
};
