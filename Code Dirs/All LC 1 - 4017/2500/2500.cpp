// Link: https://leetcode.com/problems/delete-greatest-value-in-each-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row : grid) sort(row.begin(), row.end());
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) mx = max(mx, grid[i][j]);
            total += mx;
        }
        return total;
    }
};
