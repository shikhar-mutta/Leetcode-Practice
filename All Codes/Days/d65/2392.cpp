// Link: https://leetcode.com/problems/build-a-matrix-with-conditions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(K + E), SC: O(K + E)
// Approach: DFS-based topological sort of rowConditions and colConditions independently to get
// row/col position of each value; if either has a cycle, return []. Place value v at (rowPos[v], colPos[v]).
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) return false;
            if (state[v] == 0 && !dfs(v, adj, state, order)) return false;
        }
        state[u] = 2;
        order.push_back(u);
        return true;
    }

    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> adj(k+1);
        for (auto& c : conditions) adj[c[0]].push_back(c[1]);
        vector<int> state(k+1, 0), order;
        for (int i = 1; i <= k; i++)
            if (state[i] == 0 && !dfs(i, adj, state, order)) return {};
        reverse(order.begin(), order.end());
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);
        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rowPos(k+1), colPos(k+1);
        for (int i = 0; i < k; i++) rowPos[rowOrder[i]] = i;
        for (int i = 0; i < k; i++) colPos[colOrder[i]] = i;

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int v = 1; v <= k; v++) matrix[rowPos[v]][colPos[v]] = v;
        return matrix;
    }
};
