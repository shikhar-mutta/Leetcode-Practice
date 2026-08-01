// Link: https://leetcode.com/problems/minimum-edge-toggles-on-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: toggling an edge flips both its endpoint values. Peel leaves
// one at a time (Kahn-style): for each leaf, if its current value doesn't
// match target, toggle the edge to its parent (flipping both the leaf and
// the parent), record the edge, then remove the leaf and continue with its
// parent. After peeling down to the last remaining node, it's solvable iff
// that node's value already matches target; the toggled edge set is
// necessarily minimal since each leaf's edge is the only way to affect it.
class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int,int>>> adj(n); // {neighbor, edgeIndex}
        vector<int> degree(n, 0);
        for (int i = 0; i < (int)edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            degree[u]++; degree[v]++;
        }
        vector<int> val(n);
        for (int i = 0; i < n; i++) val[i] = start[i] - '0';
        vector<bool> removed(n, false);

        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] <= 1) q.push(i);

        vector<int> result;
        int remaining = n;
        int lastNode = 0;
        while (!q.empty() && remaining > 1) {
            int u = q.front(); q.pop();
            if (removed[u]) continue;
            removed[u] = true;
            remaining--;
            int parent = -1, edgeIdx = -1;
            for (auto& [v, idx] : adj[u]) {
                if (!removed[v]) { parent = v; edgeIdx = idx; break; }
            }
            if (parent == -1) { lastNode = u; continue; }
            if (val[u] != (target[u] - '0')) {
                result.push_back(edgeIdx);
                val[u] ^= 1;
                val[parent] ^= 1;
            }
            degree[parent]--;
            if (degree[parent] == 1) q.push(parent);
            lastNode = parent;
        }
        if (val[lastNode] != (target[lastNode] - '0')) return {-1};
        sort(result.begin(), result.end());
        return result;
    }
};
