// Link: https://leetcode.com/problems/cut-off-trees-for-golf-event/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((mn)^2) SC: O(mn)
// Approach: collect all tree cells sorted by height; BFS from current position to each tree in order, summing shortest-path distances; fail if any tree is unreachable.
class Solution {
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        int m = forest.size(), n = forest[0].size();
        if (sr == tr && sc == tc) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int dist = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r+dr[d], nc = c+dc[d];
                    if (nr<0||nr>=m||nc<0||nc>=n||visited[nr][nc]||forest[nr][nc]==0) continue;
                    if (nr == tr && nc == tc) return dist;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<array<int,3>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        int total = 0;
        int curR = 0, curC = 0;
        for (auto& [h, r, c] : trees) {
            int d = bfs(forest, curR, curC, r, c);
            if (d == -1) return -1;
            total += d;
            curR = r; curC = c;
        }
        return total;
    }
};
