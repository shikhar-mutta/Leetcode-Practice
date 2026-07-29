// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N1 + N2), SC: O(N1 + N2)
// Approach: a tree is bipartite via BFS-parity coloring; nodes at even distance from i are
// exactly the nodes sharing i's color, so evenCount1[i] = size of i's own color class in tree1.
// For the bridge into tree2 attached at node i, a tree2 node w is a target iff
// 1+dist(bridgeNode,w) is even, i.e. dist(bridgeNode,w) is odd — so we want to pick the tree2
// attachment point maximizing its ODD-distance count, which is maximized by choosing a node in
// tree2's smaller color class (making the opposite/odd class the larger one); that best value is
// constant across all i. Answer[i] = evenCount1[i] + max(colorClassSize2A, colorClassSize2B).
class Solution {
public:
    pair<vector<int>, array<int,2>> bipartition(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        vector<int> color(n, -1);
        array<int,2> cnt = {0, 0};
        color[0] = 0;
        queue<int> q; q.push(0);
        cnt[0]++;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] != -1) continue;
                color[v] = color[u] ^ 1;
                cnt[color[v]]++;
                q.push(v);
            }
        }
        return {color, cnt};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        auto [color1, cnt1] = bipartition(edges1, n1);
        auto [color2, cnt2] = bipartition(edges2, n2);

        int best2 = max(cnt2[0], cnt2[1]);

        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) ans[i] = cnt1[color1[i]] + best2;
        return ans;
    }
};
