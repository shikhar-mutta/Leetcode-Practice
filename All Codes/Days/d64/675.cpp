// Link: https://leetcode.com/problems/cut-off-trees-for-golf-event/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((m*n)^2)  SC: O(m*n)
// Approach: sort trees by height, then BFS from the current position to
// each tree in order, summing shortest-path steps. Any unreachable tree
// makes the task impossible.
class Solution {
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        int m = forest.size(), n = forest[0].size();
        if (sx == tx && sy == ty) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || forest[nx][ny] == 0) continue;
                    if (nx == tx && ny == ty) return steps;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<tuple<int,int,int>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());

        int cx = 0, cy = 0, total = 0;
        for (auto& [h, tx, ty] : trees) {
            int d = bfs(forest, cx, cy, tx, ty);
            if (d == -1) return -1;
            total += d;
            cx = tx; cy = ty;
        }
        return total;
    }
};
