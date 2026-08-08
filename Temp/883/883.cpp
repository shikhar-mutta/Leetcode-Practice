// Link: https://leetcode.com/problems/projection-area-of-3d-shapes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top = 0, front = 0, side = 0;
        for (int i = 0; i < n; i++) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) top++;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            front += rowMax;
            side += colMax;
        }
        return top + front + side;
    }
};
