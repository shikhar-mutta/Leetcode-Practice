// Link: https://leetcode.com/problems/largest-magic-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMagic(vector<vector<long long>>& rowSum, vector<vector<long long>>& colSum, vector<vector<int>>& grid, int r, int c, int k) {
        long long target = rowSum[r][c + k - 1] - (c > 0 ? rowSum[r][c-1] : 0);
        for (int i = r; i < r + k; i++) {
            long long s = rowSum[i][c + k - 1] - (c > 0 ? rowSum[i][c-1] : 0);
            if (s != target) return false;
        }
        for (int j = c; j < c + k; j++) {
            long long s = colSum[r + k - 1][j] - (r > 0 ? colSum[r-1][j] : 0);
            if (s != target) return false;
        }
        long long diag1 = 0, diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[r+i][c+i];
            diag2 += grid[r+i][c+k-1-i];
        }
        return diag1 == target && diag2 == target;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<long long>> rowSum(rows, vector<long long>(cols, 0));
        vector<vector<long long>> colSum(rows, vector<long long>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowSum[i][j] = grid[i][j] + (j > 0 ? rowSum[i][j-1] : 0);
                colSum[i][j] = grid[i][j] + (i > 0 ? colSum[i-1][j] : 0);
            }
        }

        int maxK = min(rows, cols);
        for (int k = maxK; k >= 2; k--) {
            for (int r = 0; r + k <= rows; r++) {
                for (int c = 0; c + k <= cols; c++) {
                    if (isMagic(rowSum, colSum, grid, r, c, k)) return k;
                }
            }
        }
        return 1;
    }
};
