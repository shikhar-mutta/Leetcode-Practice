// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: multi-source DFS from Pacific edges (top/left) and Atlantic
// edges (bottom/right) separately, moving to higher-or-equal neighbors;
// intersect the two reachable sets
class Solution {
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= (int)h.size() || nc < 0 || nc >= (int)h[0].size()) continue;
            if (visited[nr][nc] || h[nr][nc] < h[r][c]) continue;
            dfs(h, visited, nr, nc);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
        return res;
    }
};
