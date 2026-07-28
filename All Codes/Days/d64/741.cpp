// Link: https://leetcode.com/problems/cherry-pickup/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^3)  SC: O(n^2)
// Approach: simulate two people walking from (0,0) to (n-1,n-1)
// simultaneously (equivalent to one round trip), so after `step` moves
// each is at row x, col step-x. dp[x1][x2] = max cherries collectible
// so far. Transition over the 4 combinations of (down/right) moves for
// each person; cherries at a shared cell are only counted once.
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int step = 1; step <= 2 * (n - 1); step++) {
            vector<vector<int>> ndp(n, vector<int>(n, INT_MIN));
            int xLo = max(0, step - (n - 1)), xHi = min(n - 1, step);
            for (int x1 = xLo; x1 <= xHi; x1++) {
                int y1 = step - x1;
                if (grid[x1][y1] == -1) continue;
                for (int x2 = xLo; x2 <= xHi; x2++) {
                    int y2 = step - x2;
                    if (grid[x2][y2] == -1) continue;
                    int best = INT_MIN;
                    for (int dx1 = 0; dx1 <= 1; dx1++) {
                        int px1 = x1 - dx1;
                        if (px1 < 0) continue;
                        for (int dx2 = 0; dx2 <= 1; dx2++) {
                            int px2 = x2 - dx2;
                            if (px2 < 0) continue;
                            if (dp[px1][px2] != INT_MIN) best = max(best, dp[px1][px2]);
                        }
                    }
                    if (best == INT_MIN) continue;
                    int gain = grid[x1][y1];
                    if (x1 != x2) gain += grid[x2][y2];
                    ndp[x1][x2] = best + gain;
                }
            }
            dp = ndp;
        }
        return max(0, dp[n - 1][n - 1]);
    }
};
