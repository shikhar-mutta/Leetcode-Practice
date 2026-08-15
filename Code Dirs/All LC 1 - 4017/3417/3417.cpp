// Link: https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> order;
        for (int r = 0; r < m; r++) {
            if (r % 2 == 0) {
                for (int c = 0; c < n; c++) order.push_back(grid[r][c]);
            } else {
                for (int c = n - 1; c >= 0; c--) order.push_back(grid[r][c]);
            }
        }
        vector<int> res;
        for (int i = 0; i < (int)order.size(); i += 2) res.push_back(order[i]);
        return res;
    }
};
