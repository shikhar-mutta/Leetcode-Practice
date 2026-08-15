// Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E) SC: O(V)
// Approach: BFS 2-coloring from each unvisited node; if a neighbor already has the same color as the current node, the graph isn't bipartite.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;
            color[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
