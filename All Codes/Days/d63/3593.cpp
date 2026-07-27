// Link: https://leetcode.com/problems/minimum-increments-to-equalize-leaf-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: post-order DFS. Each subtree returns the target root-to-leaf
// path sum all its leaves must share. For an internal node, gather each
// child's returned target; increasing that ONE child's own cost is
// enough to fix every leaf path under it (the delta propagates to all
// its leaves), so we only need to change nodes for children whose target
// differs from the most common one — pick the mode as this node's shared
// target to minimize changes, and return mode + cost[node] upward.
class Solution {
    vector<vector<int>>* adj;
    vector<int>* cost;
    int ans = 0;
    long long dfs(int node, int parent) {
        vector<long long> childTargets;
        for (int nxt : (*adj)[node]) {
            if (nxt == parent) continue;
            childTargets.push_back(dfs(nxt, node));
        }
        if (childTargets.empty()) return (*cost)[node];

        unordered_map<long long, int> freq;
        long long best = childTargets[0];
        int bestCount = 0;
        for (long long v : childTargets) {
            int c = ++freq[v];
            if (c > bestCount) { bestCount = c; best = v; }
        }
        ans += (int)childTargets.size() - bestCount;
        return best + (*cost)[node];
    }
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& costArr) {
        vector<vector<int>> adjacency(n);
        for (auto& e : edges) { adjacency[e[0]].push_back(e[1]); adjacency[e[1]].push_back(e[0]); }
        adj = &adjacency;
        cost = &costArr;
        ans = 0;
        dfs(0, -1);
        return ans;
    }
};
