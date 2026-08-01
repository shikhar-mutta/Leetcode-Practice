// Link: https://leetcode.com/problems/incremental-even-weighted-cycle-queries/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+m) alpha(n))  SC: O(n)
// Approach: process edges in order, adding each one only if it doesn't
// create an odd-weight cycle. Use a weighted/parity union-find: xorDist[x]
// = parity of the path from x to its stored parent, resolved via path
// compression. Different components can always be merged (a tree edge
// never creates a cycle); if u,v already share a root, the edge is only
// accepted when the induced cycle's parity (xorDist[u]^xorDist[v]^w) is
// even.
class Solution {
    vector<int> parent, xorDist;
    int find(int x) {
        if (parent[x] != x) {
            int root = find(parent[x]);
            xorDist[x] ^= xorDist[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        xorDist.assign(n, 0);

        int count = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                if ((xorDist[u] ^ xorDist[v] ^ w) == 0) count++;
            } else {
                parent[rv] = ru;
                xorDist[rv] = xorDist[u] ^ xorDist[v] ^ w;
                count++;
            }
        }
        return count;
    }
};
