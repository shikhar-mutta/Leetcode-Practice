// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> par, rnk;
    int comps;
    DSU(int n) : par(n+1), rnk(n+1, 0), comps(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        comps--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int used = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);
                if (a || b) used++;
            }
        }
        for (auto& e : edges) {
            if (e[0] == 1) { if (alice.unite(e[1], e[2])) used++; }
        }
        for (auto& e : edges) {
            if (e[0] == 2) { if (bob.unite(e[1], e[2])) used++; }
        }
        if (alice.comps != 1 || bob.comps != 1) return -1;
        return (int)edges.size() - used;
    }
};
