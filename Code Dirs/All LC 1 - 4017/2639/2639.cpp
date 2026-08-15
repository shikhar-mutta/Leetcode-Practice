// Link: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = to_string(grid[i][j]).size();
                ans[j] = max(ans[j], len);
            }
        }
        return ans;
    }
};
