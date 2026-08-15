// Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int r = 1; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] != 0) matrix[r][c] += matrix[r-1][c];
            }
        }
        int best = 0;
        for (int r = 0; r < rows; r++) {
            vector<int> row = matrix[r];
            sort(row.rbegin(), row.rend());
            for (int c = 0; c < cols; c++) {
                best = max(best, row[c] * (c + 1));
            }
        }
        return best;
    }
};
