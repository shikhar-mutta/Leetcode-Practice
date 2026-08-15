// Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> px(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> py(n + 1, vector<int>(m + 1, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int addX = (grid[i][j] == 'X') ? 1 : 0;
                int addY = (grid[i][j] == 'Y') ? 1 : 0;
                px[i+1][j+1] = addX + px[i][j+1] + px[i+1][j] - px[i][j];
                py[i+1][j+1] = addY + py[i][j+1] + py[i+1][j] - py[i][j];
                if (px[i+1][j+1] == py[i+1][j+1] && px[i+1][j+1] > 0) cnt++;
            }
        }
        return cnt;
    }
};
