// Link: https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M log(N*M)), SC: O(N*M)
// Approach: process cells in row-major order; per row and per column keep a min-heap of
// (dist, index) for already-processed cells that can still jump forward, lazily discarding
// entries whose reach no longer covers the current target. dist[cell] = 1 + best reachable
// predecessor via its row or column heap.
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        vector<priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>> rowHeap(n), colHeap(m);
        rowHeap[0].push({1, 0});
        colHeap[0].push({1, 0});

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                while (!rowHeap[i].empty()) {
                    auto [d, c] = rowHeap[i].top();
                    if (c + grid[i][c] < j) rowHeap[i].pop(); else break;
                }
                while (!colHeap[j].empty()) {
                    auto [d, r] = colHeap[j].top();
                    if (r + grid[r][j] < i) colHeap[j].pop(); else break;
                }
                int best = INT_MAX;
                if (!rowHeap[i].empty()) best = min(best, rowHeap[i].top().first + 1);
                if (!colHeap[j].empty()) best = min(best, colHeap[j].top().first + 1);
                dist[i][j] = best;
                if (best != INT_MAX) {
                    rowHeap[i].push({best, j});
                    colHeap[j].push({best, i});
                }
            }
        }

        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};
