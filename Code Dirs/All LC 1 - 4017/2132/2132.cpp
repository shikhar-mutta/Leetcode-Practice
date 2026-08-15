// Link: https://leetcode.com/problems/stamping-the-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                P[i + 1][j + 1] = P[i][j + 1] + P[i + 1][j] - P[i][j] + grid[i][j];

        auto rangeSum = [&](int r1, int c1, int r2, int c2) {
            return P[r2 + 1][c2 + 1] - P[r1][c2 + 1] - P[r2 + 1][c1] + P[r1][c1];
        };

        vector<vector<int>> D(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r + stampHeight <= m; r++) {
            for (int c = 0; c + stampWidth <= n; c++) {
                if (rangeSum(r, c, r + stampHeight - 1, c + stampWidth - 1) == 0) {
                    D[r][c]++;
                    D[r + stampHeight][c]--;
                    D[r][c + stampWidth]--;
                    D[r + stampHeight][c + stampWidth]++;
                }
            }
        }

        vector<vector<int>> cover(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = D[i][j];
                if (i > 0) val += cover[i - 1][j];
                if (j > 0) val += cover[i][j - 1];
                if (i > 0 && j > 0) val -= cover[i - 1][j - 1];
                cover[i][j] = val;
                if (grid[i][j] == 0 && val <= 0) return false;
            }
        }
        return true;
    }
};
