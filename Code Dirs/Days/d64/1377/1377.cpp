// Link: https://leetcode.com/problems/frog-position-after-t-seconds/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: DFS from node 1 tracking elapsed time and current
// probability (1/product of branching factors along the path). At each
// node, if it's a leaf (no unvisited children) or time runs out exactly
// (t==0), the frog must be sitting there for all remaining time —
// return the probability if it's the target. Otherwise recurse into
// each unvisited neighbor with probability divided by the branch count.
class Solution {
    vector<vector<int>> adj;
    double dfs(int node, int parent, int t, double prob, int target) {
        vector<int> children;
        for (int nb : adj[node]) if (nb != parent) children.push_back(nb);

        if (t == 0 || children.empty()) {
            return (node == target) ? prob : 0.0;
        }
        double share = prob / children.size();
        for (int c : children) {
            double res = dfs(c, node, t - 1, share, target);
            if (res > 0) return res;
        }
        return 0.0;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        adj.assign(n + 1, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(1, -1, t, 1.0, target);
    }
};
