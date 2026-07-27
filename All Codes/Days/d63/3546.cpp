// Link: https://leetcode.com/problems/equal-sum-grid-partition-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(1)
// Approach: total sum must be even. Scan row sums top-down accumulating
// a running prefix; if it ever equals exactly half the total (before the
// last row) a horizontal cut works. Do the same over column sums for a
// vertical cut.
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto& row : grid) for (int x : row) total += x;
        if (total % 2 != 0) return false;

        long long pre = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) pre += grid[i][j];
            if (pre * 2 == total && i != m - 1) return true;
        }

        pre = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) pre += grid[i][j];
            if (pre * 2 == total && j != n - 1) return true;
        }
        return false;
    }
};
