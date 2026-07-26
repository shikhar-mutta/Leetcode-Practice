// Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n + E) * alpha(n))
// SC: O(n)
// Approach: union-find to group nodes into connected components, then per
// component count nodes and edges (an edge belongs to a component via either
// endpoint's root). A component with k nodes is complete iff its edge count
// equals k*(k-1)/2, the max possible for a simple graph on k nodes.
class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (sz[pu] < sz[pv])
            swap(pu, pv);

        parent[pv] = pu;
        sz[pu] += sz[pv];
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build Components
        for (auto& e : edges)
            unite(e[0], e[1]);

        unordered_map<int, int> nodes;
        unordered_map<int, int> edgeCnt;

        // Count nodes in each component
        for (int i = 0; i < n; i++) {
            nodes[find(i)]++;
        }

        // Count edges in each component
        for (auto& e : edges) {
            edgeCnt[find(e[0])]++;
        }

        int ans = 0;

        for (auto& [root, cnt] : nodes) {

            int totalNodes = cnt;
            int totalEdges = edgeCnt[root];

            if (totalEdges == (totalNodes * (totalNodes - 1)) / 2)
                ans++;
        }

        return ans;
    }
};
