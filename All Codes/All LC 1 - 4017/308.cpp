// Link: https://leetcode.com/problems/range-sum-query-2d-mutable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log m * log n) update/query, O(m*n log m log n) construct  SC: O(m*n)
// Approach: 2D Fenwick tree (BIT) for point update + prefix sum query
class NumMatrix {
    vector<vector<int>> matrix, tree;
    int m, n;

    void add(int r, int c, int delta) {
        for (int i = r + 1; i <= m; i += i & (-i))
            for (int j = c + 1; j <= n; j += j & (-j))
                tree[i][j] += delta;
    }

    int prefixSum(int r, int c) {
        int sum = 0;
        for (int i = r + 1; i > 0; i -= i & (-i))
            for (int j = c + 1; j > 0; j -= j & (-j))
                sum += tree[i][j];
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        m = matrix.size();
        n = m ? matrix[0].size() : 0;
        tree.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                add(i, j, matrix[i][j]);
    }

    void update(int row, int col, int val) {
        int delta = val - matrix[row][col];
        matrix[row][col] = val;
        add(row, col, delta);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum(row2, col2) - prefixSum(row1 - 1, col2) - prefixSum(row2, col1 - 1) + prefixSum(row1 - 1, col1 - 1);
    }
};
