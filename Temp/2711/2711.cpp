// Link: https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> topLeft, bottomRight;
                for (int r = i-1, c = j-1; r >= 0 && c >= 0; r--, c--) topLeft.insert(grid[r][c]);
                for (int r = i+1, c = j+1; r < m && c < n; r++, c++) bottomRight.insert(grid[r][c]);
                ans[i][j] = abs((int)topLeft.size() - (int)bottomRight.size());
            }
        }
        return ans;
    }
};
