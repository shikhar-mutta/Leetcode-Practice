// Link: https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> par;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        par[a] = b;
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mustEdges, optEdges;
        for (auto& e : edges) {
            if (e[3] == 1) mustEdges.push_back(e);
            else optEdges.push_back(e);
        }

        // check must edges form no cycle
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        int comps = n;
        for (auto& e : mustEdges) {
            if (!unite(e[0], e[1])) return -1;
            comps--;
        }

        if (optEdges.empty()) {
            if (comps != 1) return -1;
            int minS = INT_MAX;
            for (auto& e : mustEdges) minS = min(minS, e[2]);
            return minS;
        }

        int maxS = 0;
        for (auto& e : optEdges) maxS = max(maxS, e[2]);

        long long minMustStrength = LLONG_MAX;
        for (auto& e : mustEdges) minMustStrength = min(minMustStrength, (long long)e[2]);

        auto feasible = [&](long long X) -> bool {
            if (X > minMustStrength) return false;
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            function<int(int)> f = [&](int x) { return p[x]==x ? x : p[x]=f(p[x]); };
            auto u = [&](int a, int b) { a=f(a); b=f(b); if(a==b) return false; p[a]=b; return true; };

            int comp = n;
            for (auto& e : mustEdges) { if (u(e[0], e[1])) comp--; }

            for (auto& e : optEdges) {
                if (e[2] >= X) { if (u(e[0], e[1])) comp--; }
            }
            int upgrades = 0;
            for (auto& e : optEdges) {
                if (e[2] < X && (long long)2 * e[2] >= X) {
                    if (u(e[0], e[1])) { comp--; upgrades++; }
                }
            }
            return comp == 1 && upgrades <= k;
        };

        long long lo = 1, hi = max(2LL * maxS, minMustStrength);
        if (!feasible(lo)) return -1;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid; else hi = mid - 1;
        }
        return (int)lo;
    }
};
