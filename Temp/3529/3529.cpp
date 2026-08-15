// Link: https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size(), n = grid[0].size();
        int plen = pattern.size();

        vector<vector<bool>> horiz(m, vector<bool>(n, false));
        vector<vector<bool>> vert(m, vector<bool>(n, false));

        string flatH;
        flatH.reserve(m * n);
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) flatH += grid[r][c];

        size_t pos = flatH.find(pattern);
        while (pos != string::npos) {
            for (int i = pos; i < (int)pos + plen; i++) {
                horiz[i / n][i % n] = true;
            }
            pos = flatH.find(pattern, pos + 1);
        }

        string flatV;
        flatV.reserve(m * n);
        for (int c = 0; c < n; c++)
            for (int r = 0; r < m; r++) flatV += grid[r][c];

        pos = flatV.find(pattern);
        while (pos != string::npos) {
            for (int i = pos; i < (int)pos + plen; i++) {
                vert[i % m][i / m] = true;
            }
            pos = flatV.find(pattern, pos + 1);
        }

        int count = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (horiz[r][c] && vert[r][c]) count++;
        return count;
    }
};
