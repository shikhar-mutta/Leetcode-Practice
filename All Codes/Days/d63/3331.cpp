// Link: https://leetcode.com/problems/find-subtree-sizes-after-changes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: DFS from the root, keeping prev[c] = the nearest ancestor on
// the current path whose character is c (or -1 if none). A node's
// "effective parent" for size accumulation is that same-character ancestor
// if one exists, else its original parent. After recursing into children,
// add this node's subtree size onto its effective parent's size.
// (Rewritten from a C++23 "deducing this" recursive lambda — this repo
// compiles with -std=gnu++20 — into a plain recursive member function.)
class Solution {
    vector<vector<int>> g;
    vector<int> prevSame, sz;
    string s;
    vector<int>* p;

    void dfs(int i) {
        int& same = prevSame[s[i] - 'a'];
        int old = same;
        int effParent = same == -1 ? (*p)[i] : same;
        same = i;
        for (int j : g[i])
            dfs(j);
        same = old;
        if (effParent >= 0)
            sz[effParent] += sz[i];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s_) {
        int n = parent.size();
        s = s_;
        p = &parent;
        g.assign(n, {});
        for (int i = 1; i < n; ++i)
            g[parent[i]].push_back(i);

        prevSame.assign(27, -1);
        sz.assign(n, 1);
        dfs(0);

        return sz;
    }
};
