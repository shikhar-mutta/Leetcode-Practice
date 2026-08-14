// Link: https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        // min-heaps of (dist, index) with lazy deletion
        vector<priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>> rowHeap(m), colHeap(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // already initialized
                } else {
                    while (!rowHeap[i].empty()) {
                        auto [d, col] = rowHeap[i].top();
                        if (col + grid[i][col] < j) rowHeap[i].pop();
                        else break;
                    }
                    if (!rowHeap[i].empty()) dist[i][j] = min(dist[i][j], rowHeap[i].top().first + 1);

                    while (!colHeap[j].empty()) {
                        auto [d, row] = colHeap[j].top();
                        if (row + grid[row][j] < i) colHeap[j].pop();
                        else break;
                    }
                    if (!colHeap[j].empty()) dist[i][j] = min(dist[i][j], colHeap[j].top().first + 1);
                }

                if (dist[i][j] != INT_MAX) {
                    rowHeap[i].push({dist[i][j], j});
                    colHeap[j].push({dist[i][j], i});
                }
            }
        }

        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
    }
};
