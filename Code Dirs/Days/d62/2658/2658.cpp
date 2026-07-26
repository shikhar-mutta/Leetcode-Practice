// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)
// SC: O(m*n) recursion stack worst case
// Approach: flood-fill DFS from every unvisited water cell (value > 0),
// summing fish and zeroing cells as visited (0 also naturally means land, so
// zeroing doubles as the visited marker); track the best connected-component sum.
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int best = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] > 0)
                    best = max(best, dfs(grid, i, j, m, n));
        return best;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        int fish = grid[i][j];
        grid[i][j] = 0;   // mark as visited (also fits the "land" definition)
        fish += dfs(grid, i + 1, j, m, n);
        fish += dfs(grid, i - 1, j, m, n);
        fish += dfs(grid, i, j + 1, m, n);
        fish += dfs(grid, i, j - 1, m, n);
        return fish;
    }
};
