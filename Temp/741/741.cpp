// Link: https://leetcode.com/problems/cherry-pickup/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(n^3)
// Approach: simulate two people walking simultaneously from (0,0) to (n-1,n-1), each moving right or down every step (step = r+c is the same for both). Memoize on (step, r1, r2) since c1=step-r1, c2=step-r2. At each state collect cherries from both cells (once if same cell), recurse over the 4 combinations of moves, skip paths blocked by -1.
const int NEG_INF = -1000000;
class Solution {
    int n;
    vector<vector<vector<int>>> memo;
    vector<vector<vector<bool>>> visited;
    int dfs(vector<vector<int>>& grid, int step, int r1, int r2) {
        int c1 = step - r1, c2 = step - r2;
        if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n || c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) return NEG_INF;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return NEG_INF;
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if (visited[r1][r2][step]) return memo[r1][r2][step];
        visited[r1][r2][step] = true;
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        int best = NEG_INF;
        best = max(best, dfs(grid, step+1, r1, r2));
        best = max(best, dfs(grid, step+1, r1, r2+1));
        best = max(best, dfs(grid, step+1, r1+1, r2));
        best = max(best, dfs(grid, step+1, r1+1, r2+1));
        int result = (best == NEG_INF) ? NEG_INF : cherries + best;
        return memo[r1][r2][step] = result;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(2*n-1, 0)));
        visited.assign(n, vector<vector<bool>>(n, vector<bool>(2*n-1, false)));
        int res = dfs(grid, 0, 0, 0);
        return max(res, 0);
    }
};
