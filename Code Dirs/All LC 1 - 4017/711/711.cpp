// Link: https://leetcode.com/problems/number-of-distinct-islands-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n log(m*n)) SC: O(m*n)
// Approach: DFS each island collecting its cell coordinates; generate all 8 transforms (4 rotations x reflection) of the coordinate set, normalize each by translating to origin (subtract min row/col) and sort, then take the lexicographically smallest as the canonical signature. Count distinct signatures.
class Solution {
    int m, n;
    void dfs(vector<vector<int>>& grid, int r, int c, vector<pair<int,int>>& cells) {
        if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return;
        grid[r][c] = 0;
        cells.push_back({r,c});
        dfs(grid, r-1, c, cells);
        dfs(grid, r+1, c, cells);
        dfs(grid, r, c-1, cells);
        dfs(grid, r, c+1, cells);
    }
    vector<pair<int,int>> normalize(vector<pair<int,int>> pts) {
        int minR = INT_MAX, minC = INT_MAX;
        for (auto& [r,c] : pts) { minR = min(minR, r); minC = min(minC, c); }
        for (auto& [r,c] : pts) { r -= minR; c -= minC; }
        sort(pts.begin(), pts.end());
        return pts;
    }
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        set<vector<pair<int,int>>> shapes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                vector<pair<int,int>> cells;
                dfs(grid, i, j, cells);
                vector<vector<pair<int,int>>> transforms;
                for (int t = 0; t < 8; t++) {
                    vector<pair<int,int>> tp;
                    for (auto [r,c] : cells) {
                        int x = r, y = c;
                        if (t & 1) x = -x;
                        if (t & 2) y = -y;
                        if (t & 4) swap(x, y);
                        tp.push_back({x, y});
                    }
                    transforms.push_back(normalize(tp));
                }
                shapes.insert(*min_element(transforms.begin(), transforms.end()));
            }
        }
        return shapes.size();
    }
};
