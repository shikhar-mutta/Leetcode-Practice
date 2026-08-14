// Link: https://leetcode.com/problems/find-a-good-subset-of-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int,int> firstRow;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) if (grid[i][j]) mask |= (1 << j);
            if (mask == 0) return {i};
            if (!firstRow.count(mask)) firstRow[mask] = i;
        }

        for (auto &[mask1, row1] : firstRow) {
            for (auto &[mask2, row2] : firstRow) {
                if ((mask1 & mask2) == 0) {
                    int a = min(row1, row2), b = max(row1, row2);
                    return {a, b};
                }
            }
        }
        return {};
    }
};
