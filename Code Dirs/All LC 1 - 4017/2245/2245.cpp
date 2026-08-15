// Link: https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countFactor(int x, int f) {
        int c = 0;
        while (x % f == 0) { c++; x /= f; }
        return c;
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> c2(m, vector<int>(n)), c5(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                c2[i][j] = countFactor(grid[i][j], 2);
                c5[i][j] = countFactor(grid[i][j], 5);
            }

        vector<vector<int>> rowPre2(m, vector<int>(n)), rowPre5(m, vector<int>(n));
        vector<vector<int>> rowSuf2(m, vector<int>(n)), rowSuf5(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPre2[i][j] = c2[i][j] + (j > 0 ? rowPre2[i][j-1] : 0);
                rowPre5[i][j] = c5[i][j] + (j > 0 ? rowPre5[i][j-1] : 0);
            }
            for (int j = n - 1; j >= 0; j--) {
                rowSuf2[i][j] = c2[i][j] + (j < n-1 ? rowSuf2[i][j+1] : 0);
                rowSuf5[i][j] = c5[i][j] + (j < n-1 ? rowSuf5[i][j+1] : 0);
            }
        }

        vector<vector<int>> colPre2(m, vector<int>(n)), colPre5(m, vector<int>(n));
        vector<vector<int>> colSuf2(m, vector<int>(n)), colSuf5(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPre2[i][j] = c2[i][j] + (i > 0 ? colPre2[i-1][j] : 0);
                colPre5[i][j] = c5[i][j] + (i > 0 ? colPre5[i-1][j] : 0);
            }
            for (int i = m - 1; i >= 0; i--) {
                colSuf2[i][j] = c2[i][j] + (i < m-1 ? colSuf2[i+1][j] : 0);
                colSuf5[i][j] = c5[i][j] + (i < m-1 ? colSuf5[i+1][j] : 0);
            }
        }

        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left2 = rowPre2[i][j], right2 = rowSuf2[i][j];
                int up2 = colPre2[i][j], down2 = colSuf2[i][j];
                int left5 = rowPre5[i][j], right5 = rowSuf5[i][j];
                int up5 = colPre5[i][j], down5 = colSuf5[i][j];

                best = max(best, min(left2 + up2 - c2[i][j], left5 + up5 - c5[i][j]));
                best = max(best, min(left2 + down2 - c2[i][j], left5 + down5 - c5[i][j]));
                best = max(best, min(right2 + up2 - c2[i][j], right5 + up5 - c5[i][j]));
                best = max(best, min(right2 + down2 - c2[i][j], right5 + down5 - c5[i][j]));
            }
        }
        return best;
    }
};
