// Link: https://leetcode.com/problems/power-grid-maintenance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((c + Q) log^2 c) SC: O(c)
// Approach: DSU over stations, each component root owns a sorted set of
// its currently-online station ids (merged small-into-large on union for
// efficiency). Query type 1 on x: if x is online, answer is x itself;
// otherwise the smallest id in its component's online set, or -1 if
// empty. Query type 2 on x: mark offline and erase it from its
// component's online set.
class Solution {
    vector<int> parent, sz;
    vector<set<int>*> onlineSet;
    vector<bool> offline_;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        // merge b into a (small-to-large)
        for (int v : *onlineSet[b]) onlineSet[a]->insert(v);
        delete onlineSet[b];
        onlineSet[b] = onlineSet[a];
        parent[b] = a;
        sz[a] += sz[b];
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        sz.assign(c + 1, 1);
        onlineSet.resize(c + 1);
        offline_.assign(c + 1, false);
        for (int i = 1; i <= c; i++) { parent[i] = i; onlineSet[i] = new set<int>{i}; }

        for (auto& e : connections) unite(e[0], e[1]);

        vector<int> ans;
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            if (type == 2) {
                if (!offline_[x]) {
                    offline_[x] = true;
                    onlineSet[find(x)]->erase(x);
                }
            } else {
                if (!offline_[x]) ans.push_back(x);
                else {
                    auto* s = onlineSet[find(x)];
                    ans.push_back(s->empty() ? -1 : *s->begin());
                }
            }
        }
        return ans;
    }
};
