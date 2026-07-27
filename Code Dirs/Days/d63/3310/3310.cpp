// Link: https://leetcode.com/problems/remove-methods-from-project/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n + m)
// Approach: BFS forward from k over the invocation graph to find every
// method reachable from (called by) k — the suspicious set b. Removing
// that whole set is only safe if no method OUTSIDE the set calls INTO it
// (checked via the reverse adjacency list on each node in b); if any
// non-suspicious method depends on a suspicious one, nothing can be safely
// removed and all methods remain.
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        init(n);
        for (vector<int>& i : invocations) {
            ae(e, hd, i[0], i[1]);
            ae(inv, inhd, i[1], i[0]);
        }
        queue<int> z;
        vector<bool> b(n, false);
        z.push(k);
        while (z.size()) {
            int u = z.front();
            z.pop();
            b[u] = true;
            for (int i = hd[u]; i; i = e[i].next) {
                if (!b[e[i].to]) {
                    z.push(e[i].to);
                    b[e[i].to] = true;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            if (b[i]) {
                for (int j = inhd[i]; j; j = inv[j].next)
                    if (!b[inv[j].to]) {
                        ok = false;
                        break;
                    }
            }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (ok && b[i])
                continue;
            res.push_back(i);
        }
        return res;
    }
    struct edge {
        int to, next;
        edge(int to, int next) : to(to), next(next) {}
        edge() : to(-1), next(0) {}
    };
    vector<edge> e;
    vector<edge> inv;
    vector<int> hd;
    vector<int> inhd;
    void init(int n) {
        hd.resize(n, 0);
        inhd.resize(n, 0);
        e.clear();
        inv.clear();
        e.push_back(edge());
        inv.push_back(edge());
    }
    void ae(vector<edge>& e, vector<int>& hd, int u, int v) {
        e.push_back(edge(v, hd[u]));
        hd[u] = e.size() - 1;
    }
};
