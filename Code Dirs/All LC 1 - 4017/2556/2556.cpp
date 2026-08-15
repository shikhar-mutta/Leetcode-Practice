// Link: https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 0 || grid[m-1][n-1] == 0) return true;

        vector<vector<bool>> reach1(m, vector<bool>(n, false));
        reach1[0][0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == 0) continue;
                bool ok = false;
                if (i > 0 && reach1[i-1][j]) ok = true;
                if (j > 0 && reach1[i][j-1]) ok = true;
                reach1[i][j] = ok;
            }
        }

        vector<vector<bool>> reach2(m, vector<bool>(n, false));
        reach2[m-1][n-1] = true;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                if (grid[i][j] == 0) continue;
                bool ok = false;
                if (i < m-1 && reach2[i+1][j]) ok = true;
                if (j < n-1 && reach2[i][j+1]) ok = true;
                reach2[i][j] = ok;
            }
        }

        if (!reach1[m-1][n-1]) return true;

        for (int d = 1; d <= m + n - 3; d++) {
            int count = 0;
            for (int i = max(0, d - (n-1)); i <= min(m-1, d); i++) {
                int j = d - i;
                if (j < 0 || j >= n) continue;
                if (reach1[i][j] && reach2[i][j]) count++;
            }
            if (count <= 1) return true;
        }
        return false;
    }
};
