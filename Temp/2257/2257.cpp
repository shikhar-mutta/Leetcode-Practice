// Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0=empty,1=guard,2=wall,3=guarded
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        for (auto& w : walls) grid[w[0]][w[1]] = 2;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (auto& g : guards) {
            int r = g[0], c = g[1];
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 1 && grid[nr][nc] != 2) {
                    if (grid[nr][nc] == 0) grid[nr][nc] = 3;
                    nr += dr[d]; nc += dc[d];
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) count++;
        return count;
    }
};
