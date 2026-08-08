// Link: https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E) SC: O(V)
// Approach: DFS with 3-color marking (0=unvisited,1=in-progress,2=safe); a node is safe iff all paths from it eventually reach a terminal node without hitting a cycle (in-progress node).
class Solution {
    vector<int> color;
    bool dfs(vector<vector<int>>& graph, int u) {
        if (color[u] != 0) return color[u] == 2;
        color[u] = 1;
        for (int v : graph[u]) {
            if (!dfs(graph, v)) return false;
        }
        color[u] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) if (dfs(graph, i)) res.push_back(i);
        return res;
    }
};
