// Link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: reroot technique. First post-order DFS from node 0 computes
// subtreeSize[v] and ans[0] = sum of distances from root 0. Then a
// pre-order DFS reroots: moving the root from parent u to child v
// changes the answer by +（n - subtreeSize[v]) - subtreeSize[v], since
// subtreeSize[v] nodes get 1 closer and the rest get 1 farther.
class Solution {
    vector<vector<int>> adj;
    vector<int> subtreeSize, ans;
    int n;

    void dfs1(int u, int parent) {
        subtreeSize[u] = 1;
        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs1(v, u);
            subtreeSize[u] += subtreeSize[v];
            ans[u] += ans[v] + subtreeSize[v];
        }
    }
    void dfs2(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            ans[v] = ans[u] - subtreeSize[v] + (n - subtreeSize[v]);
            dfs2(v, u);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        subtreeSize.assign(n, 0);
        ans.assign(n, 0);
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
