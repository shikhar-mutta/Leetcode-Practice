// Link: https://leetcode.com/problems/maximum-difference-score-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> minSoFar(n, vector<int>(m));
        int best = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int topMin = (i > 0) ? minSoFar[i-1][j] : INT_MAX;
                int leftMin = (j > 0) ? minSoFar[i][j-1] : INT_MAX;
                int pred = min(topMin, leftMin);
                if (pred != INT_MAX) best = max(best, grid[i][j] - pred);
                minSoFar[i][j] = min(grid[i][j], pred);
            }
        }
        return best;
    }
};
