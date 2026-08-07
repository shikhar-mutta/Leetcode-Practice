// Link: https://leetcode.com/problems/redundant-connection-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n α(n)) SC: O(n)
// Approach: find if any node has two parents (candidate1, candidate2 edges). Then run union-find on all edges, skipping candidate2 if it exists; if a cycle forms, it's caused by candidate1 (if no two-parent case) or the edge that closes the cycle otherwise (return candidate2 unless the cycle-forming edge indicates candidate1 is the answer).
class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parentOf(n+1, 0);
        vector<int> cand1, cand2;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (parentOf[v] != 0) {
                cand1 = {parentOf[v], v};
                cand2 = e;
            } else {
                parentOf[v] = u;
            }
        }
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        for (auto& e : edges) {
            if (e == cand2) continue;
            int u = e[0], v = e[1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                if (cand1.empty()) return e;
                return cand1;
            }
            parent[rv] = ru;
        }
        return cand2;
    }
};
