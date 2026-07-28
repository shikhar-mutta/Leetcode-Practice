// Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
    vector<vector<int>> up; // up[j][i] = 2^j-th ancestor of i
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        up.assign(LOG, vector<int>(n, -1));
        up[0] = parent;
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = (up[j-1][i] == -1) ? -1 : up[j-1][up[j-1][i]];
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG && node != -1; j++) {
            if (k & (1 << j)) node = up[j][node];
        }
        return node;
    }
};
