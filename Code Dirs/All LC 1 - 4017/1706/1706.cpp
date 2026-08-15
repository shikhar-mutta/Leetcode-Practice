// Link: https://leetcode.com/problems/where-will-the-ball-fall/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> res(cols);
        for (int start = 0; start < cols; start++) {
            int col = start;
            bool stuck = false;
            for (int r = 0; r < rows; r++) {
                int dir = grid[r][col];
                int nextCol = col + dir;
                if (nextCol < 0 || nextCol >= cols || grid[r][nextCol] != dir) {
                    stuck = true;
                    break;
                }
                col = nextCol;
            }
            res[start] = stuck ? -1 : col;
        }
        return res;
    }
};
