// Link: https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++)
            if (adj[i].size() % 2 == 1) odd.push_back(i);

        if (odd.size() == 0) return true;
        if (odd.size() % 2 == 1 || odd.size() > 4) return false;

        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            if (!adj[a].count(b)) return true;
            for (int c = 1; c <= n; c++) {
                if (c != a && c != b && !adj[a].count(c) && !adj[b].count(c)) return true;
            }
            return false;
        }

        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
        if (!adj[a].count(b) && !adj[c].count(d)) return true;
        if (!adj[a].count(c) && !adj[b].count(d)) return true;
        if (!adj[a].count(d) && !adj[b].count(c)) return true;
        return false;
    }
};
