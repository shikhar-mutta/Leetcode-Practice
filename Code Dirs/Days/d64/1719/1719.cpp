// Link: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& p : pairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }
        int n = adj.size();
        vector<int> nodes;
        for (auto& [k, v] : adj) nodes.push_back(k);
        sort(nodes.begin(), nodes.end(), [&](int a, int b) { return adj[a].size() > adj[b].size(); });
        if ((int)adj[nodes[0]].size() != n - 1) return 0;
        bool multiple = false;
        for (int i = 1; i < n; i++) {
            int node = nodes[i];
            int parent = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (adj[node].count(nodes[j])) { parent = nodes[j]; break; }
            }
            if (parent == -1) return 0;
            for (int nb : adj[node]) {
                if (nb == parent) continue;
                if (!adj[parent].count(nb)) return 0;
            }
            if (adj[node].size() == adj[parent].size()) multiple = true;
        }
        return multiple ? 2 : 1;
    }
};
