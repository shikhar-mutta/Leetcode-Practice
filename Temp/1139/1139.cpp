// Link: https://leetcode.com/problems/largest-1-bordered-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> left(rows, vector<int>(cols, 0)), up(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                left[i][j] = (j == 0 ? 0 : left[i][j-1]) + 1;
                up[i][j] = (i == 0 ? 0 : up[i-1][j]) + 1;
            }
        }

        int best = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int side = min(left[i][j], up[i][j]);
                while (side > best) {
                    if (left[i-side+1][j] >= side && up[i][j-side+1] >= side) {
                        best = side;
                        break;
                    }
                    side--;
                }
            }
        }
        return best * best;
    }
};
