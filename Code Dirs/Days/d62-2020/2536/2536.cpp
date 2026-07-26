// Link: https://leetcode.com/problems/increment-submatrices-by-one/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 + q)
// SC: O(n^2)
// Approach: 2D difference array. Each query marks its submatrix's 4
// corners with +1/-1 so that after a prefix sum along rows then along
// columns, every cell inside the rectangle ends up incremented by
// exactly 1 (the classic 2D range-update trick).
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (const auto& q : queries) {
            int row1 = q[0];
            int col1 = q[1];
            int row2 = q[2];
            int col2 = q[3];

            diff[row1][col1]++;
            if (col2 + 1 < n) {
                diff[row1][col2 + 1]--;
            }
            if (row2 + 1 < n) {
                diff[row2 + 1][col1]--;
                if (col2 + 1 < n) {
                    diff[row2 + 1][col2 + 1]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        return diff;
    }
};
