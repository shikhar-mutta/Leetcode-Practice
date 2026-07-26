// Link: https://leetcode.com/problems/check-knight-tour-configuration/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// SC: O(n^2) for the position-lookup table
// Approach: invert the grid into an order -> (row, col) table, then walk order
// 0..n*n-1 checking each consecutive pair is a legal knight move ((1,2) or (2,1)
// offset). Tour must also start at (0,0).
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0)
            return false; // tour must start at (0,0)

        // map each order value to its (row, col)
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                pos[grid[i][j]] = {i, j};

        for (int k = 1; k < n * n; ++k) {
            int dr = abs(pos[k].first - pos[k - 1].first);
            int dc = abs(pos[k].second - pos[k - 1].second);
            // legal knight move: (1,2) or (2,1)
            if (!((dr == 1 && dc == 2) || (dr == 2 && dc == 1)))
                return false;
        }
        return true;
    }
};
