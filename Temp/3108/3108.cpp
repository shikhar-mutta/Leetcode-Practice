// Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, rnk;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rnk.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) unite(e[0], e[1]);

        vector<int> compAnd(n, -1); // -1 = all bits set
        for (auto& e : edges) {
            int root = find(e[0]);
            compAnd[root] &= e[2];
        }

        vector<int> res;
        for (auto& q : query) {
            int u = q[0], v = q[1];
            if (u == v) { res.push_back(0); continue; }
            if (find(u) != find(v)) { res.push_back(-1); continue; }
            res.push_back(compAnd[find(u)]);
        }
        return res;
    }
};
