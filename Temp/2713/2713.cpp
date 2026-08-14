// Link: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int,int>>> byValue;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                byValue[mat[i][j]].push_back({i, j});

        vector<int> rowMax(m, 0), colMax(n, 0);
        int best = 0;

        for (auto &[val, cells] : byValue) {
            vector<int> dp(cells.size());
            for (size_t k = 0; k < cells.size(); k++) {
                auto [r, c] = cells[k];
                dp[k] = max(rowMax[r], colMax[c]) + 1;
                best = max(best, dp[k]);
            }
            for (size_t k = 0; k < cells.size(); k++) {
                auto [r, c] = cells[k];
                rowMax[r] = max(rowMax[r], dp[k]);
                colMax[c] = max(colMax[c], dp[k]);
            }
        }
        return best;
    }
};
