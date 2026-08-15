// Link: https://leetcode.com/problems/redundant-connection/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n α(n)) SC: O(n)
// Approach: union-find; process edges in order, the first edge connecting two already-connected nodes is the redundant one.
class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        for (auto& e : edges) {
            int ru = find(e[0]), rv = find(e[1]);
            if (ru == rv) return e;
            parent[ru] = rv;
        }
        return {};
    }
};
