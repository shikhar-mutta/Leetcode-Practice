// Link: https://leetcode.com/problems/spiral-matrix-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int r = rStart, c = cStart, dir = 0;
        int total = rows * cols;
        res.push_back({r, c});
        int steps = 1;
        while ((int)res.size() < total) {
            for (int rep = 0; rep < 2; rep++) {
                for (int i = 0; i < steps; i++) {
                    r += dr[dir];
                    c += dc[dir];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) res.push_back({r, c});
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        return res;
    }
};
