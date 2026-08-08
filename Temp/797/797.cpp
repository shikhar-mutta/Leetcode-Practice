// Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n) SC: O(n)
// Approach: DFS backtracking from node 0, exploring all edges; record the path when reaching node n-1.
class Solution {
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path) {
        path.push_back(node);
        if (node == (int)graph.size()-1) {
            res.push_back(path);
        } else {
            for (int next : graph[node]) dfs(graph, next, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return res;
    }
};
