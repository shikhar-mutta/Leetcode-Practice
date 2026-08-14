// Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) dp[i][0] = 0;

        int best = 0;
        for (int j = 0; j + 1 < n; j++) {
            for (int i = 0; i < m; i++) {
                if (dp[i][j] == -1) continue;
                for (int di : {-1, 0, 1}) {
                    int ni = i + di;
                    if (ni < 0 || ni >= m) continue;
                    if (grid[ni][j+1] > grid[i][j]) {
                        dp[ni][j+1] = max(dp[ni][j+1], dp[i][j] + 1);
                        best = max(best, dp[ni][j+1]);
                    }
                }
            }
        }
        return best;
    }
};
