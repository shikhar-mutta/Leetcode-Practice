// Link: https://leetcode.com/problems/rotating-the-box/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows = boxGrid.size(), cols = boxGrid[0].size();
        for (int r = 0; r < rows; r++) {
            int write = cols - 1;
            for (int c = cols - 1; c >= 0; c--) {
                if (boxGrid[r][c] == '*') {
                    write = c - 1;
                } else if (boxGrid[r][c] == '#') {
                    boxGrid[r][c] = '.';
                    boxGrid[r][write] = '#';
                    write--;
                }
            }
        }

        vector<vector<char>> res(cols, vector<char>(rows));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res[c][rows - 1 - r] = boxGrid[r][c];
            }
        }
        return res;
    }
};
