// Link: https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: collect nodes with odd degree. 0 odd -> true. 2 odd (u,v) -> true if u-v not already
// an edge, else need a third node c connected to neither u nor v (add u-c, v-c). 4 odd nodes ->
// try the 3 ways to pair them into two new non-existing edges. More than 4 odd -> false.
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n+1);
        for (auto& e : edges) { adj[e[0]].insert(e[1]); adj[e[1]].insert(e[0]); }

        vector<int> odd;
        for (int i = 1; i <= n; i++) if (adj[i].size() % 2 == 1) odd.push_back(i);

        if (odd.empty()) return true;
        if (odd.size() == 2) {
            int u = odd[0], v = odd[1];
            if (!adj[u].count(v)) return true;
            for (int c = 1; c <= n; c++) {
                if (c == u || c == v) continue;
                if (!adj[c].count(u) && !adj[c].count(v)) return true;
            }
            return false;
        }
        if (odd.size() == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            vector<array<int,4>> pairings = {{a,b,c,d},{a,c,b,d},{a,d,b,c}};
            for (auto& p : pairings) {
                if (!adj[p[0]].count(p[1]) && !adj[p[2]].count(p[3])) return true;
            }
            return false;
        }
        return false;
    }
};
