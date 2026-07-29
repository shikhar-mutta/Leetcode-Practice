// Link: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C log(R*C)), SC: O(R*C)
// Approach: group cells by value, process groups in increasing value order. For each cell,
// chain length = max(bestInRow, bestInCol) + 1 using values strictly smaller (already finalized).
// Update row/col bests only after the whole group is processed, so equal values never chain off each other.
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        map<int, vector<pair<int,int>>> byValue;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                byValue[mat[i][j]].push_back({i, j});

        vector<int> rowMax(R, 0), colMax(C, 0);
        int ans = 0;
        for (auto& [val, cells] : byValue) {
            vector<int> dp(cells.size());
            for (size_t k = 0; k < cells.size(); k++) {
                auto [r, c] = cells[k];
                dp[k] = max(rowMax[r], colMax[c]) + 1;
                ans = max(ans, dp[k]);
            }
            for (size_t k = 0; k < cells.size(); k++) {
                auto [r, c] = cells[k];
                rowMax[r] = max(rowMax[r], dp[k]);
                colMax[c] = max(colMax[c], dp[k]);
            }
        }
        return ans;
    }
};
