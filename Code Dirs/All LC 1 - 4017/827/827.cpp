// Link: https://leetcode.com/problems/making-a-large-island/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: label each island with a unique id via DFS, recording each island's size. For each 0-cell, sum the sizes of distinct neighboring islands + 1; track the max (also consider the case of no 0-cells, i.e. the whole grid is one island).
class Solution {
    int n;
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r<0||r>=n||c<0||c>=n||grid[r][c]!=1) return 0;
        grid[r][c] = id;
        return 1 + dfs(grid,r-1,c,id) + dfs(grid,r+1,c,id) + dfs(grid,r,c-1,id) + dfs(grid,r,c+1,id);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int,int> sizes;
        int id = 2;
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int sz = dfs(grid, i, j, id);
                    sizes[id] = sz;
                    best = max(best, sz);
                    id++;
                }
            }
        }
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                unordered_set<int> seen;
                for (int d = 0; d < 4; d++) {
                    int nr = i+dr[d], nc = j+dc[d];
                    if (nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]>1) seen.insert(grid[nr][nc]);
                }
                int total = 1;
                for (int s : seen) total += sizes[s];
                best = max(best, total);
            }
        }
        return best;
    }
};
