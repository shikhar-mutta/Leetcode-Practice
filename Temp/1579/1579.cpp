// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> alice(n + 1), bob(n + 1);
        iota(alice.begin(), alice.end(), 0);
        iota(bob.begin(), bob.end(), 0);

        auto findIn = [](vector<int>& p, int x) {
            while (p[x] != x) x = p[x];
            return x;
        };
        auto uniteIn = [](vector<int>& p, int a, int b) -> bool {
            function<int(int)> find = [&](int x) { while (p[x] != x) x = p[x]; return x; };
            a = find(a); b = find(b);
            if (a == b) return false;
            p[a] = b;
            return true;
        };

        int used = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                bool ua = uniteIn(alice, e[1], e[2]);
                bool ub = uniteIn(bob, e[1], e[2]);
                if (ua || ub) used++;
            }
        }
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (uniteIn(alice, e[1], e[2])) used++;
            } else if (e[0] == 2) {
                if (uniteIn(bob, e[1], e[2])) used++;
            }
        }

        int aliceRoot = findIn(alice, 1);
        for (int i = 2; i <= n; i++) if (findIn(alice, i) != aliceRoot) return -1;
        int bobRoot = findIn(bob, 1);
        for (int i = 2; i <= n; i++) if (findIn(bob, i) != bobRoot) return -1;

        return (int)edges.size() - used;
    }
};
