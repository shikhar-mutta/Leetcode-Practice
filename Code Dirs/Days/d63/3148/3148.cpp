// Link: https://leetcode.com/problems/maximum-difference-score-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(1) extra (grid reused in place to track min-so-far)
// Approach: Moving only right/down, the best score ending at (i,j) is
// grid[i][j] minus the smallest value reachable from above or left. Process
// in row-major order so grid[i-1][j]/grid[i][j-1] already hold their
// running minimum, track the best difference seen, then update grid[i][j]
// to the min of itself and that minimum for downstream cells.
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int mn = INT_MAX;

                if (i - 1 >= 0) {
                    mn = min(mn, grid[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    mn = min(mn, grid[i][j - 1]);
                }
                ans = max(ans, grid[i][j] - mn);
                grid[i][j] = min(grid[i][j], mn);
            }
        }
        return ans;
    }
};
