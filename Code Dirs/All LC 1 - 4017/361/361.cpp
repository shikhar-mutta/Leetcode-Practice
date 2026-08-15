// Link: https://leetcode.com/problems/bomb-enemy/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(n)
// Approach: for each row, precompute running enemy count until next wall
// (reset at row start / after a wall); similarly track per-column running
// counts; sum row+col count at each empty cell
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int best = 0;
        vector<int> colHits(n, 0);
        int rowHits = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        if (grid[i][k] == 'E') rowHits++;
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colHits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        if (grid[k][j] == 'E') colHits[j]++;
                }
                if (grid[i][j] == '0') best = max(best, rowHits + colHits[j]);
            }
        }
        return best;
    }
};
