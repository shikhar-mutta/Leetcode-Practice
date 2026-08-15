// Link: https://leetcode.com/problems/construct-2d-grid-matching-graph-layout/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Case 1: simple path (some node has degree 1, or n==1)
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            if ((int)adj[i].size() <= 1) { startNode = i; break; }
        }
        if (startNode != -1) {
            vector<int> path;
            vector<bool> visited(n, false);
            int cur = startNode, prev = -1;
            for (int step = 0; step < n; step++) {
                path.push_back(cur);
                visited[cur] = true;
                int next = -1;
                for (int v : adj[cur]) if (v != prev) { next = v; break; }
                prev = cur;
                cur = next;
            }
            return {path};
        }

        // Case 2: general 2D grid, find a degree-2 corner
        int corner = -1;
        for (int i = 0; i < n; i++) {
            if ((int)adj[i].size() == 2) { corner = i; break; }
        }

        auto bfs = [&](int src) {
            vector<int> d(n, -1);
            queue<int> q;
            d[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) { d[v] = d[u] + 1; q.push(v); }
                }
            }
            return d;
        };

        int A = adj[corner][0], B = adj[corner][1];
        vector<int> distCorner = bfs(corner);
        vector<int> distA = bfs(A);
        vector<int> distB = bfs(B);

        int cols = 0, rows = 0;
        for (int v = 0; v < n; v++) {
            if (distCorner[v] + 1 == distB[v]) cols = max(cols, distCorner[v] + 1);
            if (distCorner[v] + 1 == distA[v]) rows = max(rows, distCorner[v] + 1);
        }

        vector<vector<int>> grid(rows, vector<int>(cols, -1));
        for (int v = 0; v < n; v++) {
            if (distCorner[v] + 1 == distB[v]) grid[0][distCorner[v]] = v; // row0
            else if (distCorner[v] + 1 == distA[v]) grid[distCorner[v]][0] = v; // col0
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                int up = grid[r-1][c], left = grid[r][c-1], upleft = grid[r-1][c-1];
                unordered_set<int> nbUp(adj[up].begin(), adj[up].end());
                int found = -1;
                for (int v : adj[left]) {
                    if (v != upleft && nbUp.count(v)) { found = v; break; }
                }
                grid[r][c] = found;
            }
        }

        return grid;
    }
};
