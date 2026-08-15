// Link: https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool onDiag = (i == j || i + j == n - 1);
                if (onDiag && grid[i][j] == 0) return false;
                if (!onDiag && grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};
