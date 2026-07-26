// Link: https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n)
// SC: O(1) extra (mutates grid in place as visited/removed markers)
// Approach: only right/down moves exist, so run DFS from (0,0) to
// (m-1,n-1), consuming every cell it visits (setting it to 0) to model
// "this path is now used up". If no path exists at all, it's already
// disconnected. Otherwise restore the source and DFS again on the
// remaining grid: if a second path still exists, the two paths are
// forced to share only the two required endpoints, meaning they're
// otherwise disjoint and no single flip can cut both — but since a grid
// only allows right/down moves, two such paths must actually cross at
// some interior cell, so in practice this second DFS finding nothing
// means one flip suffices, and finding a path means it doesn't.
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // first DFS: find a path, marking cells visited (set to 0)
        if (!dfs(grid, 0, 0, m, n))
            return true; // no path at all: disconnected

        grid[0][0] = 1; // restore the source
        // second DFS: does another path still exist without the first one's
        // cells?
        if (!dfs(grid, 0, 0, m, n))
            return true; // no second path: one flip suffices

        return false; // two disjoint paths: can't cut with one flip
    }

private:
    bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i >= m || j >= n || grid[i][j] == 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return true; // reached destination

        grid[i][j] = 0; // mark as used (remove from graph)

        return dfs(grid, i + 1, j, m, n) || dfs(grid, i, j + 1, m, n);
    }
};
