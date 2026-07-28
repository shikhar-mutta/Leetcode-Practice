// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * 2^n)  SC: O(n * 2^n)
// Approach: BFS over states (node, visitedMask), starting from every
// single node with its own bit set. Each level is one edge traversal;
// the first time any state reaches the full mask (all nodes visited)
// gives the shortest path length.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int full = (1 << n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        queue<tuple<int,int,int>> q; // node, mask, steps
        for (int i = 0; i < n; i++) {
            visited[i][1 << i] = true;
            q.push({i, 1 << i, 0});
        }
        while (!q.empty()) {
            auto [node, mask, steps] = q.front(); q.pop();
            if (mask == full) return steps;
            for (int nb : graph[node]) {
                int nmask = mask | (1 << nb);
                if (!visited[nb][nmask]) {
                    visited[nb][nmask] = true;
                    q.push({nb, nmask, steps + 1});
                }
            }
        }
        return -1;
    }
};
